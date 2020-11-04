#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	char *pathname = argv[1];

	FILE *file = fopen(pathname, "a");
	if (file == NULL) {
		perror(pathname);
		exit(1);
	}

	int byte;
	while ((byte = fgetc(stdin)) != EOF) {
		fputc(byte, file);

		if (byte == '\n') {
			break;
		}
	}

	fclose(file);
	return 0;
}
