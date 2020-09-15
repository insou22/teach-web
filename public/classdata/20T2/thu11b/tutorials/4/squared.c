#include <stdio.h>

// Store variable x in register $t0 and store variable y in register $t1.


int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);
    y = x * x;
    printf("%d\n", y);
    return 0;
}