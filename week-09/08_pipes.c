#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int child_task(int read_pipe) {
  char to_msg[25];
  int nr;

  if ((nr = read(read_pipe, to_msg, 25)) == -1) {
    perror("child failed to read from pipe");
    return 1;
  }

  printf("child received message from parent.\n");
  printf("bytes: %d\n", nr);
  printf("message received: %s\n", to_msg);

  return 0;
}

int parent_task(int write_pipe) {
  int nw;
  char from_msg[] = "hello from parent.";

  if ((nw = write(write_pipe, from_msg, strlen(from_msg) + 1)) == -1) {
    perror("parent failed to write to pipe");
    exit(1);
  }

  printf("parent sent message to child.\n");
  printf("message sent: %s.\n", from_msg);
  printf("bytes written: %d\n", nw);

  return 0;
}

int main() {
  int parent_to_child_pipe[2];

  // Create the pipe
  if (pipe(parent_to_child_pipe) == -1) {
    perror("could not create pipe");
    exit(1);
  }

  pid_t pid;
  if ((pid = fork()) == 0) {
    // Child process...
    // First we close the write end of the pipe.
    close(parent_to_child_pipe[1]);
    exit(child_task(parent_to_child_pipe[0]));
  } else {
    // Parent process...
    // First, we close the read end of the pipe.
    close(parent_to_child_pipe[0]);
    exit(parent_task(parent_to_child_pipe[1]));

    // Wait on child process to complete
    wait(NULL);
    printf("parent process completing.\n");
  }
}
