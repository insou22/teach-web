#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t number);

int main(void) {
    
}

#define MY_MASK 0x0007D000
// 00000000 00000111 11100000 00000000
uint32_t six_middle_bits(uint32_t number) {
    // note - this will leave us with the six middle bits left in the middle.
    return number & MY_MASK;
}

#define MY_MASK_2 0x3F
// 00000000 00000000 00000000 00111111
uint32_t six_middle_bits(uint32_t number) {
    // note - this will leave us with the six middle bits at the end now.
    return (number >> 13) & MY_MASK_2;
}