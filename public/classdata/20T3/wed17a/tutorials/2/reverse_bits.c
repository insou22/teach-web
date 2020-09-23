#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t word;

word reverse_bits(word num);


int main(void) {
	word test1		= 0x00000000;
	word test1_out	= 0x00000000;
	printf("Testing that reverse_bits(0x%08X) == 0x%08X\n", test1, test1_out);
	assert(reverse_bits(test1) == test1_out);

	// 0x    0    1    2    3    4    5    6    7
	// 0b 0000 0001 0010 0011 0100 0101 0110 0111
	
	// Reversed:
	// 0b 1110 0110 1010 0010 1100 0100 1000 0000
	// 0x    E    6    A    2    C    4    8    0
	word test2		= 0x01234567;
	word test2_out	= 0xE6A2C480;
	printf("Testing that reverse_bits(0x%08X) == 0x%08X\n", test2, test2_out);
	assert(reverse_bits(test2) == test2_out);
	
	printf("All tests passed!\n");

	return 0;
}

word reverse_bits(word num) {
	word reversed = 0;

	int i = 0;
	while (i < 32) {
		word mask = 1u << i;
		word value = (num & mask) >> i;

		int rev_bit_pos = 31 - i;
		word bit_to_put = value << rev_bit_pos;

		reversed = reversed | bit_to_put;

		i++;
	}

	return reversed;
}






