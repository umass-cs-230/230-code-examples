#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void handler(int sig) {
    printf("Ouch\n");
}

int main(int argc, char *argv[]) {
    int j;
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        printf("Error calling sigaction\n");
        exit(1);
    }

    for (j=0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
}

