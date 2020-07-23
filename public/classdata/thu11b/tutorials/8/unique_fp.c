#include <stdio.h>


int main(void) {
	FILE *open1 = fopen("alphabet.txt", "r");
	FILE *open2 = fopen("alphabet.txt", "r");

	printf("open1=%p, open2=%p\n", open1, open2);

	return 0;
}


// ====== alphabet.txt ======
// open1
// abcdefghijklmnopqrstuvwxyz
//    ^
//
// open2
// abcdefghijklmnopqrstuvwxyz
// ^
//
