#include <stdlib.h> // exit
#include <stdio.h>
#include <unistd.h> // fork, pause
#include <sys/types.h>
#include <signal.h>

int main (int argc, char *argv[]) {
  pid_t pid;

  if ((pid = fork()) == 0) {
    // Child code:
    pause();
    printf("This code will never be reached...");
    exit(0);
  }

  // Parent code:
  printf("Bad child %d!\n", pid);
  kill(pid, SIGKILL);
  exit(0);
}
