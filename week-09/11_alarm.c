#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
  static int beeps = 0;

  printf("BEEP\n");
  if (++beeps < 5) {
    alarm(1);
  } else {
    printf("BOOM!\n");
    exit(0);
  }
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler);
  alarm(1);

  while (1) {
    // Signal handler returns control HERE
    // after each call.
  }
  
  exit(0);
}
