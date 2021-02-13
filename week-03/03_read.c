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
// $ man 2 read
// $ man 3 errno
// $ man 3 strerror
// $ man 3 printf
//

int main(int argc, char const *argv[]) {
  int fd = open("03_read.c", O_RDONLY);

  if (fd == -1) {
    printf("open failed. errno %i: %s\n", errno, strerror(errno));
    return 1;
  }

  char buffer[128];
  ssize_t numbytes = read(fd, buffer, 128);

  if (numbytes == -1) {
    printf("read failed. errno %i: %s\n", errno, strerror(errno));
    return 1;
  }

  if (numbytes == 0) {
    printf("the file was empty.\n");
    return 1;
  }

  printf("%i bytes read from 03_read.c:\n", numbytes);
  printf("%s\n", buffer);

  close(fd);
  return 0;
}
