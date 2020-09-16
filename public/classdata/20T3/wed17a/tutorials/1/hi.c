#include <stdio.h>

int main(void) {
    char str[10];
	// 
	// Error: Buffer overflow - no null terminating byte
	// FIX: char str[10] = { 0 };
	//
    str[0] = 'H';
    str[1] = 'i';
    printf("%s", str);
    return 0;
}
