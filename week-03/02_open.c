#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// To know which header files to include you must look at the "man page" for
// each of the calls and/or references below. For example:
//
// $ man 2 open
// $ man 3 errno
// $ man 3 strerror
// $ man 3 printf
//

int main(int argc, char const *argv[]) {
  int fd = open("02_open.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

  if (fd == -1) {
    printf("errno %i: %s\n", errno, strerror(errno));
  }

  close(fd);
  return 0;
}
