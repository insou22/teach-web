#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1025

FILE *get_file(char *pathname);
void grep_file(FILE *file, char *pathname, char *text);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <text> [files...]\n", argv[0]);
		return 1;
	}

	char *text = argv[1];

	if (argc == 2) {
		grep_file(stdin, "<stdin>", text);
	} else {
		for (int arg = 2; arg < argc; arg++) {
			char *pathname = argv[arg];
			grep_file(get_file(pathname), pathname, text);
		}
	}
	
	return 0;
}

FILE *get_file(char *pathname) {
	FILE *file = fopen(pathname, "r");
	if (file == NULL) {
		perror(pathname);
		exit(1);
	}

	return file;
}

void grep_file(FILE *file, char *pathname, char *text) {
	char line[MAX_LINE_LEN];

	int line_number = 1;
	while (fgets(line, MAX_LINE_LEN, file) != NULL) {
		if (strstr(line, text) != NULL) {
			printf("%s:%d:%s", pathname, line_number, line);
		}

		line_number++;
	}
}
