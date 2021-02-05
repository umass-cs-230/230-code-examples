#include <stdio.h>

int main() {
    unsigned char A = 0b00001010;
    unsigned char B = 0b00000110;

    // Note: we could also initialize using hex format:
    A = 0x0A;
    B = 0x06;

    printf("A is %X -> ~A is %i (base-2), %X (base-16)\n", A, ~A, ~A);
    printf("A is %X -> ~A is %i (base-2), %X (base-16) (truncated)\n\n",
           A, ~A&0x0F, ~A&0x0F);

    printf("A is %X, B is %X -> A & B is %i (base-2), %X (base-16)\n\n",
           A, B, A&B, A&B);

    printf("A is %X, B is %X -> A | B is %i (base-2), %X (base-16)\n\n",
           A, B, A|B, A|B);

    printf("A is %X, B is %X -> A ^ B is %i (base-2), %X (base-16)\n",
           A, B, A^B, A^B);
}
