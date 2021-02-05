#include <stdio.h>

int main() {
  unsigned char A = 0b10010001;  // 0x91 in hex/base-16

  // If we shift A by 2 bits to the left (A << 2) we will get 0x44.
  //
  // 10010001 << 2 =
  // 01000100
  //
  // Note:
  // 1. The higher-order (most significant) bits (01) get shifted out.
  // 2. The lower-order (least significant) bits get the value 0 shifted in.
  unsigned char result = A << 2;
  printf(
      "A is %i (base-2), %X (base-16) -> result is %i (base-2), %X "
      "(base-16)\n\n",
      A, A, result, result);

  // x << k is equivalent to x * 2^k
  result = A * 4;
  printf(
      "A is %i (base-2), %X (base-16) -> result is %i (base-2), %X (base-16)\n",
      A, A, result, result);
}
