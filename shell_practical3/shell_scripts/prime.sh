#!/bin/bash

echo "Enter a number:"
read n

echo "Prime numbers up to $n are:"
for (( i=2; i<=n; i++ ))
do
    flag=1
    for (( j=2; j<i; j++ ))
    do
        if [ $((i % j)) -eq 0 ]
        then
            flag=0
            break
        fi
    done
    if [ $flag -eq 1 ]
    then
        echo $i
    fi
done
