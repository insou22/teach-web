#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) goto if_true;
    else goto if_false;

    if_true:
    printf("medium\n");
    goto finish;

    if_false:
    printf("small/big\n");

    finish:
    return 0;
}
