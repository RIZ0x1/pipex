#!/bin/bash

#FONTS
NORMAL="\e[0m"
RED="\e[31;1;1m"
RED_BLINK="\e[31;1;5m"
GREEN="\e[32;1;1m"
BLUE="\e[34m"
YELLOW="\e[33;1;1m"

#USEFUL VARS
UNAME=$(uname)
HIDDEN_SHELL_OUT=.jcarlena_shell_out
HIDDEN_PIPEX_OUT=.jcarlena_pipex_out
HIDDEN_SHELL_ERR=.jcarlena_shell_err
HIDDEN_PIPEX_ERR=.jcarlena_pipex_err
HIDDEN_DIFF_OUT=.jcarlena_diff_out
HIDDEN_DIFF_ERR=.jcarlena_diff_err

declare -a TESTS_SHELL=(
		" < infile ls | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile cat | wc -w > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < infile grep 1 | wc -l > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < infile ping -c 1 google.com | wc -w > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile grep A -B 3 | wc -l > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR " 
		" < infile ls -R | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile ls -R | cat -e > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < this_file_does_not_exist ls | wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		" < infile /usr/bin/ls | /usr/bin/wc -c > $HIDDEN_SHELL_OUT 2> $HIDDEN_SHELL_ERR "
		)

declare -a TESTS_PIPEX=(
		" ./pipex infile 'ls' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile 'cat' 'wc -w' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR " 
		" ./pipex infile 'grep 1' 'wc -l' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile 'ping -c 1 google.com' 'wc -w' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile 'grep A -B 3' 'wc -l' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile 'ls -R' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile 'ls -R' 'cat -e' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex this_file_does_not_exist 'ls' 'wc -c' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
		" ./pipex infile '/usr/bin/ls' 'wc -l' $HIDDEN_PIPEX_OUT 2> $HIDDEN_PIPEX_ERR "
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
while [ $i -lt "$TESTS_N" ]
do
	eval "${TESTS_SHELL[$i]}"
	eval "${TESTS_PIPEX[$i]}"

	sleep 0.08
	eval diff $HIDDEN_SHELL_OUT $HIDDEN_PIPEX_OUT > $HIDDEN_DIFF_OUT
	eval diff $HIDDEN_SHELL_ERR $HIDDEN_PIPEX_ERR > $HIDDEN_DIFF_ERR

	if [ ! -s $HIDDEN_DIFF_OUT ] && [ ! -s $HIDDEN_DIFF_ERR ] ; then
		printf "$GREEN%s" "[$i] - OK"
	else
		printf "$RED%s" "[$i] - KO"
	fi
	printf "\t-->\t${TESTS_PIPEX[$i]} \n"
	((i++))
done

# ->	PERMISSIONS TEST

if [ "$UNAME" == "Darwin" ] ; then
	PERMISSIONS_TEST=$(ls -l $HIDDEN_PIPEX | grep rw-r--r--)
elif [ "$UNAME" == "Linux" ] ; then
	PERMISSIONS_TEST=$(ls -l $HIDDEN_PIPEX | grep rw-rw-r--)
elif [ "$UNAME" == "Windows" ] ; then
	echo "F#ck you, (wo)man... just go f%ck yourself"
	exit 69
fi
if [ -f $HIDDEN_PIPEX ] ; then
	if [ ! -z "$PERMISSIONS_TEST" ] ; then
		printf "\n$GREEN %s\n" "[PERMISSIONS TEST] - OK"
	else
		printf "\n$RED %s\n" "[PERMISSIONS TEST] - KO"
	fi
fi

# ->	NORME TEST

NORME=$(norminette . | grep 'Error:')

if [ ! "$NORME" ] ; then
	printf "$GREEN %s\n" "[NORME TEST] - OK"
else
	printf "$RED %s\n" "[NORME TEST] - KO"
fi

#   DELETE FILES THAT WERE CREATED BY THIS SCRIPT
rm -f $HIDDEN_PIPEX_OUT $HIDDEN_SHELL_OUT $HIDDEN_PIPEX_ERR $HIDDEN_SHELL_ERR $HIDDEN_DIFF_ERR $HIDDEN_DIFF_OUT
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi
