#include <stdio.h>

#define ROWS 6
#define COLS 12

char flag[ROWS * COLS] = {
    '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
    '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
    '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
};

// if row = 0, index ==> col (+  0)
// if row = 1, index ==> col  +  12
// if row = 2, index ==> col  +  24
// ...
//
// formula --> col + (row * 12)
//         --> (row * COLS) + col

int main(void) {
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 12; col++)
            printf ("%c", flag[(row * COLS) + col]);
        printf ("\n");
    }

}
