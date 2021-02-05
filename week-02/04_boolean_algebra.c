#include <stdio.h>

int main() {
    char A;
    char B;

    A = 0;
    printf("A is %i, ~A is %i\n\n", A, ~A);

    A = 0;
    B = 0;
    printf("A is %i, B is %i -> A & B is %i\n", A, B, A&B);

    A = 0;
    B = 1;
    printf("A is %i, B is %i -> A & B is %i\n", A, B, A&B);

    A = 1;
    B = 0;
    printf("A is %i, B is %i -> A & B is %i\n", A, B, A&B);

    A = 1;
    B = 1;
    printf("A is %i, B is %i -> A & B is %i\n\n", A, B, A&B);

    A = 0;
    B = 0;
    printf("A is %i, B is %i -> A | B is %i\n", A, B, A|B);

    A = 0;
    B = 1;
    printf("A is %i, B is %i -> A | B is %i\n", A, B, A|B);

    A = 1;
    B = 0;
    printf("A is %i, B is %i -> A | B is %i\n", A, B, A|B);

    A = 1;
    B = 1;
    printf("A is %i, B is %i -> A | B is %i\n\n", A, B, A|B);

    A = 0;
    B = 0;
    printf("A is %i, B is %i -> A ^ B is %i\n", A, B, A^B);

    A = 0;
    B = 1;
    printf("A is %i, B is %i -> A ^ B is %i\n", A, B, A^B);

    A = 1;
    B = 0;
    printf("A is %i, B is %i -> A ^ B is %i\n", A, B, A^B);

    A = 1;
    B = 1;
    printf("A is %i, B is %i -> A ^ B is %i\n", A, B, A^B);
}
