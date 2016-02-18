#!/bin/bash

FILE="out.txt"

cat ${1} > $FILE
cat ${2} >> $FILE
wc $FILE
rm $FILE
