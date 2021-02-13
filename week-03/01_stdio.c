#include <stdio.h>
#include <unistd.h>

// To know which header files to include you must look at the "man page" for
// each of the calls and/or references below. For example:
//
// $ man 3 stdin
// $ man 3 printf
//
// The stdin man page (which is also stdout and stderr) explains the
// STDIN_FILENO, STDOUT_FILENO, and STDERR_FILENO

int main(int argc, char const *argv[]) {
  printf("Standard I/O file descriptor numbers:\n");
  printf("  STDIN_FILENO : %i\n", STDIN_FILENO);
  printf("  STDOUT_FILENO: %i\n", STDOUT_FILENO);
  printf("  STDERR_FILENO: %i\n", STDERR_FILENO);
  return 0;
}
