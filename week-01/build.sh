#! /bin/env bash

# Builds the entire application with 32-bit x86 instructions without
# debugging symbols.
gcc -m32 -g main.c other.c -o app.32

# Builds the entire application with 32-bit x86 instructions and
# debugging symbols included.
gcc -m32 -g main.c other.c -o app.32.debug

# Builds the each part of the application separately with 32-bit x86
# instructions. Debugging symbols are included with main but not
# included with other.
gcc -m32 -c -g main.c
gcc -m32 -c other.c
gcc -m32 main.o other.o -o app.32.partial
