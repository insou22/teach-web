#include <stdio.h>

int fib_iter(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	int prevPrev = 0;
	int prev = 1;

	int current = 0;
	int counter = 1;
	while (counter < n) {
		current = prevPrev + prev;
		
		prevPrev = prev;
		prev = current;

		counter = counter + 1;
	}

	return current;
}

int fib_recur(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	return fib_recur(n - 1) + fib_recur(n - 2);
}

int main(void) {
	printf("Which n'th fib number? ");

	int nth;
	scanf("%d", &nth);

	int fib_val = fib_recur(nth);

	printf("The %d'th fib number is %d\n", nth, fib_val);

	return 0;
}
