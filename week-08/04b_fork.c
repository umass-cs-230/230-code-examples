#include <stdio.h>
#include <unistd.h>

int main() {
  printf("L0\n");
  if (fork() != 0) {
    printf("L1\n");    
    if (fork() != 0) {
      printf("L2\n");
      fork();
    }
  }
  printf("Bye\n");
}
