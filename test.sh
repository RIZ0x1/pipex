#!/bin/bash

#FONTS
NORMAL="\e[0m"
RED="\e[31;1;1m"
RED_BLINK="\e[31;1;5m"
GREEN="\e[32m"
BLUE="\e[34m"
YELLOW="\e[33m"

#USEFUL VARS
UNAME=$(uname)
EXEC=./pipex
HIDDEN_SHELL_OUT=.jcarlena_shell_out
HIDDEN_PIPEX_OUT=.jcarlena_pipex_out
HIDDEN_SHELL_ERR=.jcarlena_shell_err
HIDDEN_PIPEX_ERR=.jcarlena_pipex_err

declare -a TESTS_SHELL=(
		" < infile ls | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile cat | wc -w > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < infile grep 1 | wc -l > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < infile ping -c 1 google.com | wc -w > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile grep A -B 3 | wc -l > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < this_file_does_not_exist ls | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile ls -R | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile ls -R | cat -e > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		)

declare -a TESTS_PIPEX=(
		"./pipex infile 'ls' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		"./pipex infile 'cat' 'wc -w' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR" 
		"./pipex infile 'grep 1' 'wc -l' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		"./pipex infile 'ping -c 1 google.com' 'wc -w' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		"./pipex infile 'grep A -B 3' 'wc -l' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		"./pipex this_file_does_not_exist 'ls' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		"./pipex infile 'ls -R' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		" ./pipex infile 'ls -R' 'cat -e' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR"
		)

TESTS_N=${#TESTS_SHELL[@]} # array length

#WELCOME
clear
printf "$RED_BLINK
  ▘             ▝▜                   ▗           ▗          
 ▄▖  ▄▖  ▄▖  ▖▄  ▐   ▄▖ ▗▗▖  ▄▖     ▗▟▄  ▄▖  ▄▖ ▗▟▄  ▄▖  ▖▄ 
  ▌ ▐▘▝ ▝ ▐  ▛ ▘ ▐  ▐▘▐ ▐▘▐ ▝ ▐      ▐  ▐▘▐ ▐ ▝  ▐  ▐▘▐  ▛ ▘
  ▌ ▐   ▗▀▜  ▌   ▐  ▐▀▀ ▐ ▐ ▗▀▜      ▐  ▐▀▀  ▀▚  ▐  ▐▀▀  ▌  
  ▌ ▝▙▞ ▝▄▜  ▌   ▝▄ ▝▙▞ ▐ ▐ ▝▄▜      ▝▄ ▝▙▞ ▝▄▞  ▝▄ ▝▙▞  ▌  
  ▌                                                         
 ▀ \n$NORMAL"

#START
#   COMPILING
printf "$BLUE************************************************************* \n"

make all
make clean

printf "************************************************************* \n"
printf "$NORMAL"

#   CREATE INFILE IF DOES NOT EXISTS
if [ ! -s ./infile ] || [ -z ./infile ] ; then
	printf "$YELLOW"
	printf "============================================================= \n"
	printf "WARNING: YOUR ./infile IS EMPTY OR DOES NOT EXIST \n"
	printf "WARNING: CREATING DEFAULT ./infile ... \n"
	printf "============================================================= \n"
	printf "$NORMAL"
	
	touch ./infile && IN=1
	echo "1" > ./infile
	echo "12" >> ./infile
	echo "123" >> ./infile
	echo "ABCDEFG GFEFDCBA" >> ./infile
	echo "" >> ./infile
	echo "Ares: You are still just a mortal! " >> ./infile
	echo "    Every bit as weak as that day you begged me to save your life!" >> ./infile
	echo "Kratos: I am not the same man you found that day." >> ./infile
	echo "    The monster you've created has returned... to kill you!" >> ./infile
	echo "Ares: You have no idea what a true monster is Kratos!" >> ./infile
	echo "    Your final lesson IS AT HAND!" >> ./infile
fi

#   TESTS RUNNING
i=0
while [ $i -lt $TESTS_N ]
do
	eval ${TESTS_SHELL[$i]}
	eval ${TESTS_PIPEX[$i]}

	RESULT_OUT=$(diff $HIDDEN_SHELL_OUT $HIDDEN_PIPEX_OUT)
	RESULT_ERR=$(diff $HIDDEN_SHELL_ERR $HIDDEN_PIPEX_ERR)
	if [ -z "$RESULT_OUT" ] && [ -z "$RESULT_ERR" ] ; then
		printf "$GREEN[$i] - OK"
	else
		printf "$RED[$i] - KO"
	fi
	printf "\t-->\t${TESTS_PIPEX[$i]} \n"
	sleep 0.05
	((i++))
done

# ->	PERMISSIONS TEST

if [ $UNAME == "Darwin" ] ; then
	PERMISSIONS_TEST=$(ls -l $HIDDEN_PIPEX | grep rw-r--r--)
elif [ $UNAME == "Linux" ] ; then
	PERMISSIONS_TEST=$(ls -l $HIDDEN_PIPEX | grep rw-rw-r--)
elif [ $UNAME == "Windows" ] ; then
	echo "F#ck you, man... just go f%ck yourself"
fi
if [ -f $HIDDEN_PIPEX ] ; then
	if [ ! -z "$PERMISSIONS_TEST" ] ; then
		printf "\n$GREEN[PERMISSIONS TEST] - OK\n"
	else
		printf "\n$RED[PERMISSIONS TEST] - KO\n"
	fi
fi

#   DELETE FILES THAT WERE CREATED BY THIS SCRIPT
#rm -f $HIDDEN_PIPEX_OUT $HIDDEN_SHELL_OUT $HIDDEN_PIPEX_ERR $HIDDEN_SHELL_ERR
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi