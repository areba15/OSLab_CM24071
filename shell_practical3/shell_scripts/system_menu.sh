#!/bin/bash

echo "1. Display current month calendar"
echo "2. Display today's date and time"
echo "3. Display logged in users"
echo "4. Display terminal number"
echo "Enter your choice:"
read ch

case $ch in
1) date +"%B %Y" ;;
2) date ;;
3) who ;;
4) tty ;;
*) echo "Invalid choice" ;;
esac

