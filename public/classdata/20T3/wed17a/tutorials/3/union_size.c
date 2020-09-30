#include <stdio.h>

union {
	int a;
	int b;
} u1;


union {
	unsigned short a;
	char b;
} u2;


union {
	int a;
	char b[12];
} u3;


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
	printf("u1: %lu bytes\n", sizeof(u1));
	printf("u2: %lu bytes\n", sizeof(u2));
	printf("u3: %lu bytes\n", sizeof(u3));
	printf("u4: %lu bytes\n", sizeof(u4));
	printf("u5: %lu bytes\n", sizeof(u5));

	return 0;	
}
