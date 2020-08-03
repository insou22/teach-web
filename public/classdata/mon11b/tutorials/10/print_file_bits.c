#include <stdio.h>
#include <stdint.h>


int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}

	char *file_name = argv[1];

	FILE *file = fopen(file_name, "r");

	uint32_t current;
	while (fscanf(file, "%x", &current) == 1) {
		int8_t lsb = current & 0xFF;

		printf("%hhx\n", lsb);
	}

	return 0;
}

