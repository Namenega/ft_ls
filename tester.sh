#!/bin/bash

# Basic colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
CYAN='\033[0;35m'
PURPLE='\033[0;36m'
WHITE='\033[0;37m'
# Reset color
END='\033[0m'

# ------------------------ Banner ------------------------
echo "+-----------------------------------------------------------------------+"
echo "|.+-------------------------------------------------------------------+ |"
echo "|.| \t\t\t${YELLOW}Tester for ft_ls${END}\t\t\t      |.|"
echo "|.|\t\t\t\t\t\t\t\t      |.|"
echo "|.| ${YELLOW}Author${END}: Namenega\t\t\t\t\t\t      |.|"
echo "|.|\t\t\t\t\t\t\t\t      |.|"
echo "|.| ${PURPLE}Every tests compare './ft_ls' to the real command 'ls'${END}\t      |.|"
echo "|.+-------------------------------------------------------------------+ |"
echo "+-----------------------------------------------------------------------+"
echo ""


function compare_files {
	if diff -q "$1" "$2" >/dev/null; then
		# files are the same
		echo "[${GREEN}OK${END}]"  # print "[OK]" in green
	else
		# files are different
		echo "[${RED}FAIL${END}]"  # print "[FAIL]" in dark red
	fi
}

# ------------------------ Starting tests ------------------------

# Testing no arguments
echo "Test ${RED}1${END} : ${PURPLE} ls${END}"
./ft_ls > a.txt
ls > b.txt
compare_files a.txt b.txt

# Testing current directory
echo "Test ${RED}2${END} : ${PURPLE} ls .${END}"
./ft_ls . > a.txt
ls . > b.txt
compare_files a.txt b.txt

# Testing ls -
#----> ls: -: No such file or directory
echo "Test ${RED}2${END} : ${PURPLE} ls -${END}"
./ft_ls - > a.txt
ls - > b.txt
compare_files a.txt b.txt

# Testing ls --
#----> normal output
# echo "Test ${RED}2${END} : ${PURPLE} ls --${END}"
# ./ft_ls -- > a.txt
# ls -- > b.txt
# compare_files a.txt b.txt

# Testing ls ---
#----> ls: unrecognized option `---'
#----> usage: ls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwxy1%,] [--color=when] [-D format] [file ...]
# echo "Test ${RED}2${END} : ${PURPLE} ls ---${END}"
# ./ft_ls --- > a.txt
# ls --- > b.txt
# compare_files a.txt b.txt

# Testing ls -a--
#----> ls: unrecognized option `---'
#----> usage: ls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwxy1%,] [--color=when] [-D format] [file ...]
# echo "Test ${RED}2${END} : ${PURPLE} ls -a--${END}"
# ./ft_ls -a-- > a.txt
# ls -a-- > b.txt
# compare_files a.txt b.txt

# Testing ls ---a
#----> ls: unrecognized option `---a'
#----> usage: ls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwxy1%,] [--color=when] [-D format] [file ...]
# echo "Test ${RED}2${END} : ${PURPLE} ls ---a${END}"
# ./ft_ls ---a > a.txt
# ls ---a > b.txt
# compare_files a.txt b.txt

# Testing ls -a--a
#----> ls: unrecognized option `---a'
#----> usage: ls [-@ABCFGHILOPRSTUWabcdefghiklmnopqrstuvwxy1%,] [--color=when] [-D format] [file ...]
# echo "Test ${RED}2${END} : ${PURPLE} ls -a--a${END}"
# ./ft_ls -a--a > a.txt
# ls -a--a > b.txt
# compare_files a.txt b.txt
