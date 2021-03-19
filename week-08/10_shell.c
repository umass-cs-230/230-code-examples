#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * example usage: ./01_shell /bin/echo "hello, world"
 */

int main (int argc, char *argv[], char *envp[]) {
  // An argument array:
  char *new_argv[128];

  // Make the first entry the program to execute:
  new_argv[0] = argv[1];

  // setup additional command line arguments:
  int i;
  for (i = 2; i < argc; i++) {
    new_argv[i-1] = argv[i];
  }
  new_argv[i-1] = NULL;

  // child process id:
  int pid;

  if ((pid = fork()) == 0) {
    // Child code:
    if (execve(new_argv[0], new_argv, envp) < 0) {
      printf("%s: command not found.\n", new_argv[0]);
      exit(0);
    }
  } else {
    // Parent code:
    int status;
    if (waitpid(pid, &status, 0) < 0) {
      printf("waitpid error!\n");
    }
  }

  return 0;
}

