#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void child_handler (int sig) {
  static int hits = 3;
  if (hits > 0) {
    printf("\nMissed me! Try again!\n");
    hits--;
  } else {
    printf("\nArrrrg! You got me! RIP.\n");
    exit(0);
  }
}

void parent_handler (int sig) {
  if (sig == SIGCHLD) {
    printf("\nChild has been killed!\n");
    printf("\nReaping...\n");
    int status;
    wait(&status);   
    exit(0);
  } else {
    printf("\nchild not dead yet.\n");
  }
}

int main (int argc, char *argv[]) {
  if (fork() == 0) {
    if (signal(SIGINT, child_handler) == SIG_ERR) {
      printf("signal error.\n");
    }

    while (1) {
      // Signal handler returns control HERE
      // after each call.
      printf("Hiding...\n");
      fflush(stdout);
      pause();
    }
  } else {
    if (signal(SIGCHLD, parent_handler) == SIG_ERR) {
      printf("signal error.\n");
    }
    if (signal(SIGINT, parent_handler) == SIG_ERR) {
      printf("signal error.\n");
    }
    while (1) {
      // Loop until child dies.
    }  	
  }
  return 0;
}
