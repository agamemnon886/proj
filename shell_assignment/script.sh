#!/bin/bash

# Read next line from the 'ifconfig -a' output
while read -r line; do
	# Get values of the 'inet addr' and 'Mask' fields and pass them to 'awk'
	# to print in table format
	echo $line | sed -n  's/inet addr:\([0-9.][0-9.][0-9.]*\).*Mask:\([0-9.][0-9.][0-9.]*\)/\1 \2/p' | awk '{printf "%-14s == %-14s\n", $1, $2}'
done < <(ifconfig -a)

