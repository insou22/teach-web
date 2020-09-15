#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENV_VAR "HOME"

int main(int argc, char *argv[]) {
	char *home = getenv(ENV_VAR);

	if (home == NULL) {
		fprintf(stderr, "%s: could not find environment variable %s.\n", argv[0], ENV_VAR);
		return 1;
	}

	//  /home/zac + / + .diary  ==> /home/zac/.diary
	char *file_name = ".diary";

	size_t size = strlen(home) + 1 + strlen(file_name) + 1;
	char path[size];

	snprintf(path, size, "%s/%s", home, file_name);

	FILE *diary_file = fopen(path, "r");
	if (diary_file == NULL) {
		perror(path);
		return 1;
	}

	int ch;
	while ((ch = fgetc(diary_file)) != EOF) {
		putchar(ch);
	}

	fclose(diary_file);
	return 0;
}
