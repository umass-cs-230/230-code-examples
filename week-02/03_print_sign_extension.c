#include <stdio.h>

int main() {
  short int sx = -12345;
  unsigned short int usx = sx;  // The bits are copied from sx to usx
  int x = sx;                   // The sign is extended to larger type
  unsigned int ux = usx;        // A zero is extended to larger unsigned type

  printf("short int sx is %i (base-2), %hX (base-16)\n", sx, sx);
  printf("unsigned short int usx is %i (base-2), %X (base-16)\n", usx, usx);
  printf("int x is %i (base-2), %X (base-16)\n", x, x);
  printf("unsigned int ux is %i (base-2), %X (base-16)\n", ux, ux);
}
