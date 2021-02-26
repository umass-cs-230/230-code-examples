#include <stdio.h>

int adder2(int a) {
    return a + 2;
}

int main() {
    int x = 40;
    x = adder2(x);
    printf("x is %d\n", x);
    return 0;
}
