#!/bin/bash

# FONTS
NORMAL="\033[0m"
RED="\033[31;1;1m"
RED_BLINK="\033[31;1;5m"
GREEN="\033[32m"
BLUE="\033[34m"
# USEFUL VARS
EXEC=./pipex

# WELCOME
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

# START
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



#   DELETE IN- OR/AND OUTFILE IF THEY WERE CREATED BY THIS SCRIPT
if [ "$IN" = 1 ] ; then rm -f ./infile ; fi
if [ "$OUT" = 1 ] ; then rm -f ./outfile ; fi