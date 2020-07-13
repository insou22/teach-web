#include <stdio.h>

int fib(int n);

int main(void) {
	int nth;
	printf("Enter n: ");
	scanf("%d", &nth);

	int nthFib = fib(nth);

	printf("The %d'th fibonacci number is %d.\n", nth, nthFib);
	return 0;
}

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	int prev1 = fib(n - 1);
	int prev2 = fib(n - 2);

	return prev1 + prev2;
}

