#!/bin/bash

#FONTS
NORMAL="\033[0m"
RED="\033[31;1;1m"
RED_BLINK="\033[31;1;5m"
GREEN="\033[32m"
BLUE="\033[34m"

#USEFUL VARS
EXEC=./pipex
HIDDEN_PIPEX=./.pipex_file
HIDDEN_SHELL=./.shell_file

IFS='#'
TESTS_SHELL="< infile ls | wc -c > outfile # < infile cat | wc -c > outfile"
TESTS_PIPEX="./pipex infile ''ls'' ''wc -c'' outfile # ./pipex infile 'cat' | 'wc -c' outfile"

#WELCOME
clear
echo $RED_BLINK
echo "
  ▘             ▝▜                   ▗           ▗          
 ▄▖  ▄▖  ▄▖  ▖▄  ▐   ▄▖ ▗▗▖  ▄▖     ▗▟▄  ▄▖  ▄▖ ▗▟▄  ▄▖  ▖▄ 
  ▌ ▐▘▝ ▝ ▐  ▛ ▘ ▐  ▐▘▐ ▐▘▐ ▝ ▐      ▐  ▐▘▐ ▐ ▝  ▐  ▐▘▐  ▛ ▘
  ▌ ▐   ▗▀▜  ▌   ▐  ▐▀▀ ▐ ▐ ▗▀▜      ▐  ▐▀▀  ▀▚  ▐  ▐▀▀  ▌  
  ▌ ▝▙▞ ▝▄▜  ▌   ▝▄ ▝▙▞ ▐ ▐ ▝▄▜      ▝▄ ▝▙▞ ▝▄▞  ▝▄ ▝▙▞  ▌  
  ▌                                                         
 ▀ "
echo $NORMAL

#START
#   COMPILING
echo $BLUE
echo "************************************************************"

make all
make clean

echo "************************************************************"
echo $NORMAL

#   CREATE IN- AND OUTFILE IF DOES NOT EXISTS
if [ ! -f ./infile ] ; then touch ./infile && IN=1 ; fi
if [ ! -f ./outfile ] ; then touch ./outfile && OUT=1 ; fi

#   TEST CASES

for i in $TESTS_SHELL ;
do
	eval $TESTS_SHELL > $HIDDEN_SHELL
	eval $TESTS_PIPEX > $HIDDEN_PIPEX
	RESULT=$(diff $HIDDEN_SHELL $HIDDEN_PIPEX)

	if [ -z $RESULT ]; then
		echo $OK
	else
		echo $KO
	fi
done

rm -f $HIDDEN_PIPEX $HIDDEN_SHELL

#   DELETE IN- OR/AND OUTFILE IF THEY WERE CREATED BY THIS SCRIPT
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi
if [ "$OUT" = 1 ] ; then rm -f ./outfile ; fi