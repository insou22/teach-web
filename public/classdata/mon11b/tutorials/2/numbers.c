#include <stdio.h>

//                       8421
// 1        0x1     0000 0001
// 8        0x8     0000 1000
// 10       0xa     0000 1010
// 15       0xf     0000 1111
// 16       0x10    0001 0000

// a    0x5555   0101 0101 0101 0101
// b    0xaaaa   1010 1010 1010 1010
// c    0x0001   0000 0000 0000 0001

// a | b         1111 1111 1111 1111    0xFFFF
// a & b         0000 0000 0000 0000    0x0000
// a ^ b         1111 1111 1111 1111    0xFFFF
// a & ~b        0101 0101 0101 0101    0x5555
// c << 6        0000 0000 0100 0000    0x0040
// a >> 5        0000 0010 1010 1010    0x02AA

/*
#define READING   0x01   0000 0001
#define WRITING   0x02   0000 0010
#define AS_BYTES  0x04   0000 0100
#define AS_BLOCKS 0x08   0000 1000
#define LOCKED    0x10   0001 0000
*/

// int control = 0000 0111;
// if (control & READING) { the control is reading from the device }
// if (control & AS_BYTES) { the control is reading as bytes }
// i want the control to now be locked:
// control = control | LOCKED;

int main(void) {
    while (1) {
        printf("Please enter a decimal number: ");

        int input;
        int result = scanf("%d", &input);

        if (!result) {
            break;
        }

        printf("%d = %03o = %2x\n", input, input, input);
    }

    printf("Thanks for playing!\n");

    return 0;
}