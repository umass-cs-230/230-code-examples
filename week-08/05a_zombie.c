#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  if (fork() == 0) {
    /* Child */
    printf("Terminating Child, PID = %d\n",
           getpid());
    exit(0);
  } else {
    printf("Running Parent, PID = %d\n",
           getpid());
    while (1)
      ; /* Infinite loop */
  }
}
