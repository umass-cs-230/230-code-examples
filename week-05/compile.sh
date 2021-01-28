#! /bin/env bash

# App Example 1
gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.1.c
gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -g app.1.c -o app.1

# App Example 2
gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.2.c
gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -g app.2.c -o app.2
