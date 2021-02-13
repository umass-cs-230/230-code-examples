#! /bin/env bash

# Builds each of the C files with 32-bit x86 instructions with
# debugging symbols
#
gcc -m32 -g -Wall 01_stdio.c -o 01_stdio
gcc -m32 -g -Wall 02_open.c -o 02_open
gcc -m32 -g -Wall 03_read.c -o 03_read
gcc -m32 -g -Wall 04_write.c -o 04_write
gcc -m32 -g -Wall 05_copy.c -o 05_copy