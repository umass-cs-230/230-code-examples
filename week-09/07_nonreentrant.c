#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>

static char *str2;
static int handled = 0;

static void handler(int sig) {
    crypt(str2, "xx");
    handled++;
}

int main(int argc, char *argv[]) {
    char *cr1;
    int callNum;
    int mismatch;
    struct sigaction sa;

    if (argc != 3) {
        printf("usage: %s str1 str2\n", argv[0]);
        exit(1);
    }

    str2 = argv[2];
    cr1 = strdup(crypt(argv[1], "xx"));

    if (cr1 == NULL) {
        printf("Error calling strdup\n");
        exit(1);
    }

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        printf("Error calling sigaction\n");
        exit(1);
    }

    for (callNum = 1, mismatch = 0; ; callNum++) {
        if (strcmp(crypt(argv[1], "xx"), cr1) != 0) {
            mismatch++;
            printf("Mismatch on call %d (mismatch=%d handled=%d)\n",
                   callNum, mismatch, handled);
        }
    }

    return 0;
}
