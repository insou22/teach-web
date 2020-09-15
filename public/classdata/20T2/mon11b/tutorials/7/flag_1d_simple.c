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
	int row = 0;

main_row_cond:
	if (row >= ROWS) goto main_row_end;

		int col = 0;

main_col_cond:
		if (col >= COLS) goto main_col_end;

			printf ("%c", flag[(row * COLS) + col]);
			col++;
			goto main_col_cond;

main_col_end:
        printf ("\n");
		row++;
		goto main_row_cond;

main_row_end:

	return 0;
}













