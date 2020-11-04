#include <stdio.h>
#include <stdlib.h>

int read_bort(FILE* file);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	char *pathname = argv[1];

	FILE *file = fopen(pathname, "r");
	if (file == NULL) {
		perror(pathname);
		exit(1);
	}
	
	// BIG ENDIAN
	// 00000001 00000011

	// LITTLE ENDIAN
	// 00000011 00000001
	
	int counter = 0;
	int bort;
	while ((bort = read_bort(file)) != EOF) {
		printf("bort %4d: %d\n", counter, bort);
		counter++;
	}

	fclose(file);
	return 0;
}

int read_bort(FILE* file) {
	int byte1 = fgetc(file);
	if (byte1 == EOF) {
		return EOF;
	}

	int byte2 = fgetc(file);
	if (byte2 == EOF) {
		return EOF;
	}

	return (byte2 << 8) | byte1;
}
