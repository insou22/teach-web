#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	char *home = getenv("HOME");

	if (home == NULL) {
		fprintf(stderr, "Error: No HOME environment variable\n");
		return 1;
	}

	char *diary_name = ".diary";

	//			  /home/zac     /    .diary             \0
	int length = strlen(home) + 1 + strlen(diary_name) + 1;
	char diary_path[length];
	snprintf(diary_path, length, "%s/%s", home, diary_name);

	FILE *diary = fopen(diary_path, "r");

	int ch;
	while ((ch = fgetc(diary)) != EOF) {
		putchar(ch);
	}

	return 0;
}

