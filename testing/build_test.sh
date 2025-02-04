#! /usr/bin/env bash

if [ $# -ne 1 ]; then
	echo "usage: $0 <num>"
	echo -e "\tnum ... version num for test<num>.c"
	exit
else
	num=$1
fi

fname="test${num}"

if [ ! -f ${fname}.c ]; then
	echo "${fname}.c: No such file!"
	exit
fi

set -xe
gcc -Wall -o ./bin/${fname} ./${fname}.c ./substrcheck.c ./substrcheck.h

