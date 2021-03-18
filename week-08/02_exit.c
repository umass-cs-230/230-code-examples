#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cleanup(void) { printf("cleaning up 1\n"); }

void cleanup2(void) { printf("cleaning up 2\n"); }

void cleanup3(void) { printf("cleaning up 3\n"); }

int main() {
  atexit(cleanup);
  atexit(cleanup2);
  atexit(cleanup3);
  printf("I am here!\n");
  // exit(0);
  printf("I am now here! not!\n");
}
