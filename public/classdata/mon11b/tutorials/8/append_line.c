#include <stdio.h>

// 0: stdin
// 1: stdout
// 2: stderr

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	FILE *my_file = fopen(argv[1], "a");

	// if the fopen failed
	if (my_file == NULL) {
		perror(argv[1]);

		return 1;
	}

	int ch;
	while ((ch = fgetc(stdin)) != EOF) {
		fputc(ch, my_file);

		if (ch == '\n') {
			break;
		}
	}

	fclose(my_file);

	return 0;
}
