#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void remove_public_write(char *pathname);

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		char *pathname = argv[i];
		remove_public_write(pathname);
	}

	return 0;
}


void remove_public_write(char *pathname) {
	struct stat buf;
	if (stat(pathname, &buf) != 0) {
		perror(pathname);
		exit(1);
	}

	mode_t mode = buf.st_mode;

	if (mode & S_IWOTH) {
		printf("removing public write from %s\n", pathname);

		mode_t bitmask  = ~S_IWOTH;
		mode_t new_mode = mode & bitmask;

		if (chmod(pathname, new_mode) != 0) {
			perror(pathname);
			exit(1);
		}

	} else {
		printf("%s is not publically writable\n", pathname);
	}
}
