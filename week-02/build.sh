#! /bin/env bash

# Builds each of the C files with 32-bit x86 instructions with
# debugging symbols
gcc -m32 01_print_chars.c -o 01_print_chars
gcc -m32 02_print_sizes.c -o 02_print_sizes
gcc -m32 03_print_sign_extension.c -o 03_print_sign_extension
gcc -m32 04_boolean_algebra.c -o 04_boolean_algebra
gcc -m32 05_bit_manipulations.c -o 05_bit_manipulations
gcc -m32 06_shifting.c -o 06_shifting
gcc -m32 07_extracting_bits_method_1.c -o 07_extracting_bits_method_1
gcc -m32 08_extracting_bits_method_2.c -o 08_extracting_bits_method_2
