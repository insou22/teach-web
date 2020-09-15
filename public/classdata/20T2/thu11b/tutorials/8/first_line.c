#include <stdio.h>


int main(int argc, char *argv[]) {
	if (argc < 2) {
        fprintf(stderr, "%s <name of file>\n", argv[0]);
        return 1;
    }
 
    char *file_name = argv[1];
	
	FILE *my_file = fopen(file_name, "r");

	if (my_file == NULL) {
		fprintf(stderr, "%s ", argv[0]);
        perror(file_name);
		return 1;
	}

	int my_char;
	while ( (my_char = fgetc(my_file)) != EOF) {
		putchar(my_char); // or printf("%c", my_char);

		if (my_char == '\n') {
			break;
		}
	}

	return 0;
}
