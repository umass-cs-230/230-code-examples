#include <stdio.h>

unsigned char extract(unsigned int L, unsigned int R, unsigned char value);

int main() {
  // Let's define a value to mask.
  // Typically, we are using only unsigned types when we are dealing with
  // extracting a range of bits.
  unsigned char value = 0b00011100;  // 0x1C

  // Bits are numbered from right to left.
  // 0  0  0  1  1  1  0  0
  // b7 b6 b5 b4 b3 b2 b1 b0    (b as in "bit")

  // Imagine we want to "extract" bits 1-3.
  // Step 1: shift left eliminating high bits
  // Step 2: shift right eliminating low bits
  //
  // We extract the bits using left and right shifting
  // This is what happens:
  // 00011100 << 4 = 11000000
  // 00001100 >> 5 = 00000110
  unsigned char step_1 = value << 4;
  unsigned char step_2 = step_1 >> 5;
  unsigned char result = step_2;

  printf("Manual Method:\n");
  printf("Value is %X\n", value);
  printf("Extracted value is %X\n\n", result);

  // Extracting bits L through R
  // We can use the generic `extract` function to do the, well, extraction!
  result = extract(3, 1, value);

  printf("Generic Method:\n");
  printf("Value is %X\n", value);
  printf("Extracted value is %X\n\n", result);
}

// Extracting bits L through R
unsigned char extract(unsigned int L, unsigned int R, unsigned char value) {
  unsigned int n = sizeof(value) * 8;  // size of the type in bits
  unsigned int left_shift = n - (L + 1);
  unsigned int right_shift = n - (L - R + 1);

  unsigned char step_1 = value << left_shift;
  unsigned char step_2 = step_1 >> right_shift;

  return step_2;
}