#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

char read_next_char(int fd) {
    char buffer[1];

    // We initialize the buffer to 'z' in case we reach the end of the
    // file. We decided the behavior of this program is to simply
    // return 'z' forever if we reach the end of the file.
    buffer[0] = 'z';

    // Note: we are ignoring the return value of read to simplify the
    // code for illustrative purposes. In a real program you would
    // want to check the return value. A -1 indicates some I/O
    // error. A 0 indicates the end of the file.
    read(fd, buffer, 1);

    return buffer[0];
}

int main() {
    int fd = open("alphabet.txt", 'r');

    char ch = read_next_char(fd);
    printf("Before Fork: %c\n", ch);

    pid_t pid = fork();
    if (pid) {
        // In parent.
        sleep(2);
        ch = read_next_char(fd);
        printf("Parent: %c\n", ch);
        sleep(1);
        ch = read_next_char(fd);
        printf("Parent: %c\n", ch);
    }
    else {
        // In child.
        sleep(1);
        ch = read_next_char(fd);
        printf("Child: %c\n", ch);
        sleep(1);
        ch = read_next_char(fd);
        printf("Child: %c\n", ch);
    }

    // Reap the child process before completing main.
    wait(NULL);

    return 0;
}
