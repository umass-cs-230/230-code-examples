#include <stdio.h>

int create_mask(int L, int R);

int main() {
    // Let's define a value to mask. 
    // Typically, we are using only unsigned types when we are dealing with
    // shifting and masking.
    unsigned char value = 0b00011100; // 0x1C

    // Bits are numbered from right to left.
    // 0  0  0  1  1  1  0  0
    // b7 b6 b5 b4 b3 b2 b1 b0    (b as in "bit")

    // Imagine we want to "extract" bits 1-3.
    // We need to create a mask for this (0xE in hex).
    unsigned char mask = 0b00001110;

    // We extract the bits using bitwise and (&) and then
    // shift to the right by 1 since we are grabbing the
    // bits from 1-3. If we were grabbing bits 2-3 we would
    // shift by 2.
    //
    // This is what happens:
    // 00011100 & 00001110 = 00001100
    // 00001100 >> 1 = 00000110
    // which 0x6 in hex and 6 in decimal.
    unsigned char extracted_value = (value & mask) >> 1;
    printf("Value is %X\n", value);
    printf("Mask is %X\n", mask);  
    printf("Extracted value is %X\n\n", extracted_value); 

    // This is an example using our create_mask function that will automatically
    // generate a mask for us given the bit range we want to extract.
    mask = create_mask(3, 1);
    extracted_value = (value & mask) >> 1;
    printf("Value is %X\n", value);
    printf("Mask is %X\n", mask);  
    printf("Extracted value is %X\n", extracted_value); 
}

int create_mask(int L, int R) {
    // See lesson slides for additional details.
    unsigned int step_1 = ((1 << (L-R+1))-1);
    unsigned int step_2 = step_1 << R;
    return step_2;
}