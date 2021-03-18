#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  if (fork() == 0) {
    /* Child */
    printf("Running Child, PID = %d\n",
           getpid());
    while (1)
      ; /* Infinite loop */
  } else {
    printf("Terminating Parent, PID = %d\n",
           getpid());
    exit(0);
  }
}
