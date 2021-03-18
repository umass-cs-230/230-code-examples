#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
 * Run the following program.
 * Kill the processes in the same group using the kill command:
 *
 *  $ kill -9 -<pgid>
 *
 * -9 is the SIGKILL signal and you fill in <pgid> with the
 * process group id that is displayed from this program.
 */
int main (int argc, char const *argv[]) {
  if (fork() == 0) {
    printf("Child1: pid=%d pgrp=%d\n", getpid(), getpgrp());
    if (fork() == 0) {
      printf("Child2: pid=%d pgrp=%d\n", getpid(), getpgrp());
    }
    while(1);
  }	
  return 0;
}
