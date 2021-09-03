#!/bin/bash

#FONTS
NORMAL="\e[0m"
RED="\e[31;1;1m"
RED_BLINK="\e[31;1;5m"
GREEN="\e[32m"
BLUE="\e[34m"
YELLOW="\e[33m"

#USEFUL VARS
EXEC=./pipex
HIDDEN_SHELL=.shell_file
HIDDEN_PIPEX=.pipex_file

declare -a TESTS_SHELL=(
		" < infile ls | wc -c > $HIDDEN_SHELL "
		" < infile cat | wc -c > $HIDDEN_SHELL " 
		" < infile grep 1 | wc -c > $HIDDEN_SHELL " 
		" < infile ping -c 2 google.com | wc -w > $HIDDEN_SHELL "
		" < infile grep A -A 2 -B 3 | wc -l > $HIDDEN_SHELL " 
		" < this_file_does_not_exists ls | wc -c > $HIDDEN_SHELL ")

declare -a TESTS_PIPEX=(
		"./pipex infile 'ls' 'wc -c' $HIDDEN_PIPEX "
		"./pipex infile 'cat' 'wc -c' $HIDDEN_PIPEX " 
		"./pipex infile 'grep 1' 'wc -c' $HIDDEN_PIPEX "
		"./pipex infile 'ping -c 2 google.com' 'wc -w' $HIDDEN_PIPEX "
		"./pipex infile 'grep A -A 2 -B 3' 'wc -l' $HIDDEN_PIPEX " 
		"./pipex this_file_does_not_exists 'ls' 'wc -c' $HIDDEN_PIPEX" )

TESTS_N=5

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
printf "$BLUE************************************************************ \n"

make all
make clean

printf "************************************************************* \n"
printf "$NORMAL"

#   CREATE INFILE IF DOES NOT EXISTS
if [ ! -s ./infile ] || [ -z ./infile ] ; then
	printf "$YELLOW"
	printf "============================================================= \n"
	printf "WARNING: YOUR ./infile IS EMPTY OR NOT EXISTS \n"
	printf "WARNING: CREATING DEFAULT INFILE... \n"
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
fi

#   TESTS RUNNING
i=0
while [ $i -le $TESTS_N ]
do
	eval ${TESTS_SHELL[$i]} 2> /dev/null > $HIDDEN_SHELL
	eval ${TESTS_PIPEX[$i]} 2> /dev/null > $HIDDEN_PIPEX

	RESULT=$(diff $HIDDEN_SHELL $HIDDEN_PIPEX)
	if [ -z "$RESULT" ]; then
		printf "$GREEN[$i] - OK"
	else
		printf "$RED[$i] - KO"
	fi
	printf "\t-->\t${TESTS_PIPEX[$i]} \n"
	sleep 0.05
	((i++))
done

#   DELETE FILES WHICH WAS CREATED BY THIS SCRIPT
rm -f $HIDDEN_PIPEX $HIDDEN_SHELL
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi