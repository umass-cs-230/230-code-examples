#include <stdio.h>

int main() {
    int a;
    short int b;
    unsigned int c;
    char d;

    printf("size of an int is %i bytes\n", (int)sizeof(a));
    printf("size of a short int is %i bytes\n", (int)sizeof(b));
    printf("size of an unsigned int is %i bytes\n", (int)sizeof(c));
    printf("size of a character is %i byte\n", (int)sizeof(d));
}
