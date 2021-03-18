#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char const *argv[]) {
  int mypid = getpid();
  // getpid returns the process id of *this* process:
  printf("My process id = %d\n", mypid);
  
  // getppid returns the process id of the *parent* process:
  printf("My parents process id = %d\n", getppid());
  
  return 0;
}
