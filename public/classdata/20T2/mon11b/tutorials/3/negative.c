#include <stdio.h>

// 13 decimal
//                8421
// 0000 0000 0000 1101

// 0x0013
// 0000 0000 0001 0011 = 19dec


// 0xffff
// 1111 1111 1111 1111 -> this is a negative number
// 0000 0000 0000 0000 # step 1 - flip all the bits
// 0000 0000 0000 0001 # step 2 - add 1.
// therefore -> -1

// 0x8000
// 1000 0000 0000 0000 -> this is a negative number
// 0111 1111 1111 1111 # step 1
// 1000 0000 0000 0000 # step 2 - add 1 
// this makes -32768

// 100
// 0000 0000 0110 0100

// To make -100:
// 0000 0000 0110 0100 = 100
// 1111 1111 1001 1011 # step 1
// 1111 1111 1001 1100 # step 2
// -100

//   100 + (-100) = 0
//   0000 0000 0110 0100 +
//   1111 1111 1001 1100
//(1)0000 0000 0000 0000 # discard overflowed bit
//   0000 0000 0000 0000 # 0!

int main(void) {

    //  number = 60000?
    short number = (short) ((short) 30000 + (short) 30000);
    printf("%hd\n", number); // prints -5536

    //                                          note: for unsigned int, you can just do  30000u
    unsigned short number2 = (unsigned short) ((unsigned short) 30000 + (unsigned short) 30000);
    printf("%hu\n", number2); // prints 60000

    return 0;
}