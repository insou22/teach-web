#include <stdio.h>
#include <stdint.h>


int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	FILE *file = fopen(argv[1], "r");

	uint32_t current;
	while (fscanf(file, "%x", &current) == 1) {
		int8_t lsb = current & 0xFF;

		printf("%d\n", lsb);
	}

	return 0;
}
