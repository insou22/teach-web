//
// Sample solution for COMP1521 lab exercises
//
// Convert string of binary digits to 16-bit signed integer

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define N_BITS 16

int16_t sixteen_in(char *bits);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        printf("%d\n", sixteen_in(argv[arg]));
    }

    return 0;
}

/*
./sixteen_in   0000 0000 0000 0000
./sixteen_in   1111 1111 1111 1111
./sixteen_in 1 0000 0000 0000 0000
./sixteen_in   0000 0000 0000 0000
0

./sixteen_in 0000 0000 0000 0001
1

./sixteen_in 1111 1111 1111 1111
-1

./sixteen_in 0011 0011 0011 0011
13107

./sixteen_in 1111 0000 1111 0000
-3856
*/

// DONT DO THIS
#define BIT_1 0b00000001
#define BIT_2 0b00000010
#define BIT_3 0b00000100
#define BIT_4 0b00001000

// Rather, how can we create a bitmask similar to above
// without #define'ing every single bit individually?
// Is there a way we could use a variable to go through each
// of the bits in our value and use that to set them individually?
// Maybe a loop might be useful?

//
// given a string of binary digits ('1' and '0')
// return the corresponding signed 16 bit integer
//
int16_t sixteen_in(char *bits) {

    int16_t value = 0;

    // ................

    return value;
}
