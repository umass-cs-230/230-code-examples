#include <stdlib.h> // exit
#include <stdio.h>
#include <unistd.h> // fork, pause
#include <sys/types.h>
#include <signal.h>
#include <string.h>

/*
 * Run the following program.
 * Send a SIGINT signal like so:
 *
 *  $ kill -2 <pid>
 *
 * -2 is the SIGINT signal and you fill in <pid> with the
 * child pid that is displayed from this program.
 */

void handler (int sig) {
  printf("handler was called for signal %d\n", sig);
}

int main (int argc, char *argv[]) {
  pid_t pid;

  if ((pid = fork()) == 0) {
    signal(SIGINT, handler);
    // Child code:
    pause();
    printf("We will execute this code!\n");
    exit(0);
  }

  printf("child pid = %d\n", pid);

  sleep(1);
  // Parent code:
  if (argc > 1 && strcmp(argv[1],"p") == 0) {
    printf("Bad child %d!\n", pid);
    kill(pid, SIGINT);
  }
  exit(0);
}
