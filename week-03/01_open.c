#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd = open("01_open.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  close(fd);
  return 0;
}
