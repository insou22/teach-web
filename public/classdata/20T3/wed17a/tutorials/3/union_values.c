#include <stdio.h>

union _all {
   int   ival;
   char cval;
   char  sval[4];
   float fval;
   unsigned int uval;
};


int main(void) {
	union _all var;

	var.uval = 0x00313233;

	printf("%x\n", var.uval);
	printf("%d\n", var.ival);
	printf("%c\n", var.cval);
	printf("%s\n", var.sval);
	printf("%f\n", var.fval);
	printf("%e\n", var.fval);

	return 0;
}
