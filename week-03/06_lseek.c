#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // The length of the data file is the number of letters in the
  // alphabet times 2 minus 1 because we are using 0 indexing minus 1
  // as we do not have a trailing space at the end of the file.
  //
  // a b c d ... z
  // 0 2 4 6 ... 50
  //
  int data_file_length = (26 * 2) - 2;

  if (argc < 2) {
    printf("Usage: %s INDEX\n", argv[0]);
    return 1;
  }

  int index = atoi(argv[1]);

  if ((index * 2) >= data_file_length) {
    printf("Index must be less than data_file_length.\n");
    return 1;
  }

  int fd = open("06.dat", O_RDONLY);
  if (fd == -1) {
    printf("open failed\n");
    return 1;
  }

  off_t offset = lseek(fd, index * 2, SEEK_SET);
  if (offset == -1) {
    printf("lseek failed\n");
    return 1;
  }

  char buffer[2];
  ssize_t nbytes = read(fd, buffer, 1);
  if (nbytes == -1) {
    printf("read failed\n");
    return 1;
  }

  buffer[1] = '\0';
  printf("Data at index %i is %s\n", index, buffer);

  return 0;
}
