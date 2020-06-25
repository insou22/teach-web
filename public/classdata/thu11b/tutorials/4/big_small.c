#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) goto if_true;
    goto if_false;

if_true:
    printf("medium");
    goto end;
    
if_false:
    printf("small/big");
    goto end; // not needed

end:
    printf("\n");
    return 0;
}
