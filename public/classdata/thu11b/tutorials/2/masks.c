#include <stdio.h>
#include <stdint.h>

#define READING   0x01  // 0000 0001
#define WRITING   0x02  // 0000 0010
#define AS_BYTES  0x04  // 0000 0100
#define AS_BLOCKS 0x08  // 0000 1000
#define LOCKED    0x10  // 0001 0000
                        // 1110 1111

int main(void) {
    unsigned char device = 0; // 0001 0010

    // device = device | READING | LOCKED;
    device = device | WRITING | LOCKED;
    device = device & ~LOCKED;

    if (device & WRITING) {
        // the device is reading
    }
}