#include <stdio.h>
#include <stdlib.h>

#define MAX_PATHNAME_LEN 128

int main(void) {
	char *home_dir = getenv("HOME");
	if (home_dir == NULL) {
		fprintf(stderr, "No $HOME environment variable found!\n");
		return 1;
	}


	char buf[MAX_PATHNAME_LEN];
	snprintf(buf, sizeof(buf), "%s/.diary", home_dir);

	FILE *file = fopen(buf, "r");
	if (file == NULL) {
		perror(buf);
		return 1;
	}

	int ch;
	while ((ch = fgetc(file)) != EOF) {
		putchar(ch);
	}

	return 0;
}

