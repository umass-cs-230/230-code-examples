#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define N 10

int main() {
  pid_t pid[N];
  int i;
  int child_status;
  for (i = 0; i < N; i++) {
    if ((pid[i] = fork()) == 0) {
      exit(100+i); /* Child */
    }
  }
  for (i = 0; i < N; i++) {
    pid_t wpid = wait(&child_status);
    if (WIFEXITED(child_status)) {
      printf("Child %d terminated with exit status %d\n",
             wpid, WEXITSTATUS(child_status));
    } else {
      printf("Child %d terminate abnormally\n", wpid);
    }
  }
}
