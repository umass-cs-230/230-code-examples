#! /bin/env bash

# Instructions for compiling these code examples on your own Linux
# system:
#
# https://askubuntu.com/questions/91909/trouble-compiling-a-32-bit-binary-on-a-64-bit-machine
#
# Here we are compiling code to target the x86 32-bit instructions. If
# this does not work and you receive the following error (or something
# like it):
#
# fatal error: bits/libc-header-start.h: No such file or directory
#
# You will need to install the 32-bit support:
#
# sudo apt-get update
# sudo apt-get install gcc-multilib
#

# These flags are used to generate the simplest assembly
# representation from the C code.
FLAGS="-m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -g"

gcc $FLAGS -o 01_assign 01_assign.c
gcc $FLAGS -o 02_modified 02_modified.c

# App Example 1
#gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.1.c
#gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -g app.1.c -o app.1

# App Example 2
#gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.2.c
#gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -g app.2.c -o app.2
