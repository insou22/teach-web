#include <stdio.h>
#include <stdlib.h>

int global_int = 3;
int global_int_array[1000];

int main(void) {
	int stack_int = 5;
	int *malloc_int = malloc(sizeof(int));

	printf("my malloced int = %d\n", *malloc_int);

	printf("location of text  = %16p\n", &main);
	printf("location of glob  = %16p\n", &global_int);
	printf("location of heap  = %16p\n", malloc_int);
	printf("location of stack = %16p\n", &stack_int);

	free(malloc_int);
}
