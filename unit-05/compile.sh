#! /bin/env bash

gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.1.c
gcc -m32 -fno-stack-protector -fno-asynchronous-unwind-tables -fno-exceptions -fno-pic -O0 -S app.2.c
