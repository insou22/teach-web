#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t word;

word reverse_quads(word num);
void test_reverse_quads(word input, word output);


// reverse_quads should take an input number, and reverse the bits,
//   but in groups of 4! i.e.:
// 
// 0b 0000 0001 0010 0011 0100 0101 0110 0111
// 
// would be reversed into:
//
// 0b 0111 0110 0101 0100 0011 0010 0001 0000
//
// This also has the effect of reversing the number in terms of
//   its hexadecimal digits, as each hex digit is 4 bytes!
//
// Make sure you understand the question fully before starting!!
//   If you're confused about what the question is asking,
//   have a look at the test cases in main(), and then ask
//   someone for clarification!
word reverse_quads(word num) {

	// TODO: Your code goes in here!
	
	return num;
}



int main(void) {
	test_reverse_quads(0x00000000, 0x00000000);

	test_reverse_quads(0x00000001, 0x10000000);
	test_reverse_quads(0x10000000, 0x00000001);
	
	test_reverse_quads(0x10101010, 0x01010101);
	test_reverse_quads(0x01010101, 0x10101010);
	
	test_reverse_quads(0x12345678, 0x87654321);
	test_reverse_quads(0x87654321, 0x12345678);
	
	printf("All tests passed!\n");

	return 0;
}



void test_reverse_quads(word input, word output) {
	printf("Testing that reverse_quads(0x%08X) == 0x%08X ... ", input, output);
	assert(reverse_quads(input) == output);
	printf(" (passed)\n");
}

