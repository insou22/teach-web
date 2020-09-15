#include <stdio.h>

// 4 bytes
union {
    int a;
    int b;
} u1;

// 2 bytes
union {
    unsigned short a;
    char b;
} u2;

// 12 bytes
union {
    int a;
    char b[12];
} u3;

// 16??? bytes
union {
    int a;
    char b[14];
} u4;

union {
    unsigned int a;
    int b;
    struct {
        int x;
        int y;
    } c;
} u5;

int main(void) {
    printf("%lu %lu %lu %lu %lu\n", sizeof(u1), sizeof(u2), sizeof(u3), sizeof(u4), sizeof(u5));

}