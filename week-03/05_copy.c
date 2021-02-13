#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fdin;   // The file descriptor for the SOURCE file.
  int fdout;  // The file descriptor for the DESTINATION file.

  char buffer[1024];  // The buffer to fill with bytes.

  // Check the number of arguments to make sure we have 3.
  if (argc != 3) {
    printf("Usage: %s SOURCE DESTINATION\n", argv[0]);
    return 1;
  }

  // Open the source file as read only.
  if ((fdin = open(argv[1], O_RDONLY)) < 0) {
    printf("Could not open source file %s\n", argv[1]);
    return 2;
  }

  // Open the destination file as write only.
  if ((fdout = open(argv[2], O_WRONLY | O_CREAT)) < 0) {
    printf("Could not open destination file %s\n", argv[2]);
    return 3;
  }

  // The number of bytes we read in.
  int bytes_read_in = 0;

  // Keep reading bytes in 1024 byte chunks.
  while ((bytes_read_in = read(fdin, buffer, 1024)) > 0) {
    int buffer_index = 0;       // An index into the buffer.
    int bytes_written_out = 0;  // The number of bytes written out.

    // Keep writing bytes out from the buffer until there is nothing left.
    while ((bytes_written_out = write(fdout, &buffer[buffer_index],
                                      bytes_read_in)) < bytes_read_in) {
      // If the return value from write is < 0 then there was an error.
      if (bytes_written_out < 0) {
        printf("Error writing to file %s\n", argv[2]);
        return 5;
      }

      // Decrement the number of bytes left.
      bytes_read_in -= bytes_written_out;

      // Increment the buffer index by the number of bytes written.
      buffer_index += bytes_written_out;
    }
  }

  if (bytes_read_in < 0) {
    return 4;
  }

  close(fdin);
  close(fdout);
}
