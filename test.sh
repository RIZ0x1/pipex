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

TESTS_N=2

declare -a TESTS_SHELL=( " < infile ls | wc -c > outfile "
		" < infile cat | wc -c > outfile " )

declare -a TESTS_PIPEX=( "./pipex infile 'ls' 'wc -c' outfile "
		"./pipex infile 'cat' 'wc -c' outfile" )


#WELCOME
clear
echo "
  ▘             ▝▜                   ▗           ▗          
 ▄▖  ▄▖  ▄▖  ▖▄  ▐   ▄▖ ▗▗▖  ▄▖     ▗▟▄  ▄▖  ▄▖ ▗▟▄  ▄▖  ▖▄ 
  ▌ ▐▘▝ ▝ ▐  ▛ ▘ ▐  ▐▘▐ ▐▘▐ ▝ ▐      ▐  ▐▘▐ ▐ ▝  ▐  ▐▘▐  ▛ ▘
  ▌ ▐   ▗▀▜  ▌   ▐  ▐▀▀ ▐ ▐ ▗▀▜      ▐  ▐▀▀  ▀▚  ▐  ▐▀▀  ▌  
  ▌ ▝▙▞ ▝▄▜  ▌   ▝▄ ▝▙▞ ▐ ▐ ▝▄▜      ▝▄ ▝▙▞ ▝▄▞  ▝▄ ▝▙▞  ▌  
  ▌                                                         
 ▀ "

#START
#   COMPILING
echo "************************************************************"

make all
make clean

echo "************************************************************"

#   CREATE IN- AND OUTFILE IF DOES NOT EXISTS
if [ ! -f ./infile ] ; then touch ./infile && IN=1 ; fi
if [ ! -f ./outfile ] ; then touch ./outfile && OUT=1 ; fi

#   TEST CASES

i=0
while [ $i -le $TESTS_N ]
do
	eval ${TESTS_SHELL[$i]} > $HIDDEN_SHELL
	eval ${TESTS_PIPEX[$i]} > $HIDDEN_PIPEX

	RESULT=$(diff $HIDDEN_SHELL $HIDDEN_PIPEX)
	if [ -z "$RESULT" ]; then
		echo "[$i] - OK"
		echo ''
	else
		echo "[$i] - ERROR"
		echo ''
	fi
	((i++))
done

rm -f $HIDDEN_PIPEX $HIDDEN_SHELL

#   DELETE IN- OR/AND OUTFILE IF THEY WERE CREATED BY THIS SCRIPT
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi
if [ "$OUT" = 1 ] ; then rm -f ./outfile ; fi