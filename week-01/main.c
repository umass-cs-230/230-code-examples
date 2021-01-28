#include <stdio.h>

void hidden();

int sum(int a, int b) {
    int c = a + b;
    return c;
}

int sumsum(int a, int b) {
    int c = sum(a, b) + sum(a, b);
    return c;
}

int main(int argc, char* argv[]) {
    int x = 4;
    int y = 5;
    int z = sum(4, 5);
    printf("The sum is %d\n", z);

    z = sumsum(x, y);
    printf("The sumsum is %d\n", z);

    hidden();

    int arr[12];
    for (int i = 0; i < 12; i++) {
        arr[i] = 0;
    }

    if (arr[5] == 1) {
        printf("It worked!\n");
    }
}
