#include <stdio.h>
#include <stdint.h>

/*

a | b (bitwise OR)
a & b (bitwise AND)
a ^ b (bitwise XOR)
a & ~b (bitwise AND)
c << 6 (left shift)
a >> 4 (right shift)
a & (b << 1)
b | c
a & ~c

*/

// uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;

int main(void) {
    // a: 0x5555
    //                8421
    // 0101 0101 0101 0101

    // b: 0xAAAA
    // 1010 1010 1010 1010

    // c: 0x0001
    // 0000 0000 0000 0001

    uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;

    // a | b
    // 1111 1111 1111 1111

    // a & b
    // 0000 0000 0000 0000

    // a ^ b
    // 1111 1111 1111 1111

    // a & ~b (bitwise AND)
    // 0101 0101 0101 0101

    // c << 6 (left shift)
    // 0000 0000 0100 0000

    // a >> 4 (right shift)
    // 0000 0101 0101 0101

    return 0;
}