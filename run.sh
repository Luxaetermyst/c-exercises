#!/bin/bash
# Usage:
#   ./run.sh <path-to-problem>          -> uses input.txt if it exists, otherwise reads from the keyboard
#   ./run.sh <path-to-problem> --manual -> reads from the keyboard
dir="$1"
if [ -z "$dir" ]; then
    echo "Usage: ./run.sh <path-to-problem> [--manual]"
    exit 1
fi
gcc "$dir/main.c" -o "$dir/main" || exit 1
if [ "$2" = "--manual" ] || [ ! -f "$dir/input.txt" ]; then
    "$dir/main"
else
    "$dir/main" < "$dir/input.txt"
fi
