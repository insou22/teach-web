#include <stdio.h>


int main(int argc, char *argv[]) {
	if (argc < 2) {
        fprintf(stderr, "%s <name of file>\n", argv[0]);
        return 1;
    }
 
    char *file_name = argv[1];
	
	FILE *my_file = fopen(file_name, "w");

	if (my_file == NULL) {
		fprintf(stderr, "%s ", argv[0]);
        perror(file_name);
		return 1;
	}

	char buf[100];
	fgets(buf, 100, stdin); // be careful - not checking errors
	fputs(buf, my_file);


	return 0;
}
