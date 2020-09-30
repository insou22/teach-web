#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t x);


int main(void) {

	//									101011
	uint32_t my_number = 0b10010001001001010110100100101001;

	printf("%x\n", six_middle_bits(my_number));

	return 0;
}


uint32_t six_middle_bits(uint32_t x) {
	uint32_t my_mask = 0b00000000000001111110000000000000;

	uint32_t masked = x & my_mask;

	return masked >> 13;
}
