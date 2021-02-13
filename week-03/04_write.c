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
// $ man 2 write
// $ man 3 errno
// $ man 3 strerror
// $ man 3 printf
//

int main(int argc, char const *argv[]) {
  int fd = open("04_write.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

  if (fd == -1) {
    printf("open failed. errno %i: %s\n", errno, strerror(errno));
    return 1;
  }

  char buffer[1024];
  size_t length = strlen("COMPSCI 230 is Awesome!\n");
  strncpy(buffer, "COMPSCI 230 is Awesome!\n", length + 1);
  ssize_t numbytes = write(fd, buffer, length);

  if (numbytes == -1) {
    printf("write failed. errno %i: %s\n", errno, strerror(errno));
    return 1;
  }

  printf("%i bytes written to 04_write.txt:\n", numbytes);
  printf("Bytes written: %s", buffer);

  close(fd);
  return 0;
}
