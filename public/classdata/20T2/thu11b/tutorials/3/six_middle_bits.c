#include <stdio.h>
#include <stdint.h>

#define SIX_MIDDLE_SHIFT 13
#define SIX_BIT_MASK 0x3F;

uint8_t six_middle_bits(uint32_t number);


int main(void) {
    // prints 63 as 6 middle bits are all 1's
    printf("%d\n", six_middle_bits(0b1100101011111110000110100000));
}

//                 <----->
// 0000 0000 0000 0111 1110 0000 0000 0000
uint8_t six_middle_bits(uint32_t number) {
// 0000 0000 0000 0000 0000 0000 0011 1111
    uint32_t shifted = number >> SIX_MIDDLE_SHIFT;
    
    uint32_t number_masked = shifted & SIX_BIT_MASK;

    return number_masked;
}