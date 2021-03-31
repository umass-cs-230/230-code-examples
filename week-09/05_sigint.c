#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        struct sigaction sa;

        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sa.sa_handler = child_handler;
        if (sigaction(SIGINT, &sa, NULL) == -1) {
            printf("Error calling sigaction\n");
            exit(1);
        }

        while (1) {
            // Signal handler returns control HERE
            // after each call.
            printf("Hiding...\n");
            fflush(stdout);
            pause();
        }
    } else {
        struct sigaction sa;

        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sa.sa_handler = parent_handler;
        if (sigaction(SIGCHLD, &sa, NULL) == -1) {
            printf("Error calling sigaction\n");
            exit(1);
        }

        if (sigaction(SIGINT, &sa, NULL) == -1) {
            printf("Error calling sigaction\n");
            exit(1);
        }

        while (1) {
            // Loop until child dies.
        }
    }
    return 0;
}
