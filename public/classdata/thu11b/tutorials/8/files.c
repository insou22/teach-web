#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// argv[0] argv[1]
// ./files <name of file>
int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "%s <name of file>\n", argv[0]);
		return 1;
	}

	char *file_name = argv[1];

	// fd -> a unique way to talk about a particular open file
	// say, we open "foo.txt", and get fd 5
	// if we open "foo.txt" again, we may get fd 6.
	//
	// and, an fd integrates the idea of a "cursor"
	// -- a cursor is a current position in the file that we
	//		will read from, or write to. 
	//		the cursor starts at the beginning of the file.
	//
	// FUN FACT: stdin = fd 0, stdout = fd 1 (and stderr = fd 2)
	int fd = open(file_name, O_RDONLY);
	
	if (fd == -1) {
		fprintf(stderr, "%s ", argv[0]);
		perror(file_name);
		return 1;
	}

	char buf[4];
	ssize_t n_bytes;

	while ( (n_bytes = read(fd, buf, 4)) > 0 ) {
		for (int i = 0; i < n_bytes; i++) {
			putchar(buf[i]);
		}
		printf(" ");
	}

	printf("\nFinished reading from file!\n");

	return 0;
}



// =========== foo.txt ===========
// Hello, World!
// ^

