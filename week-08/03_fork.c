#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    printf("hello from child %d parent pid is %d\n", getpid(), getppid());
  } else {
    printf("hello from parent %d child is %d\n", getpid(), pid);
  }
}
