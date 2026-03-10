#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursive_sum(int n);
int recursive_mul(int n);

int level = 0;

int main(void) {
	srand(time(NULL));
	int i;
	for (i = 1; i <= 20; i++) {
		if (i<=10) {
			level = 0;
			printf("Factorial(%d): %d\n", i, recursive_mul(i));
			printf("\n");
		} else {
			level = 0;
			printf("Sum(%d): %d\n", i, recursive_sum(i));
			printf("\n");
		}
	}
	return 0;
}

int recursive_sum(int n) {
	printf("%*s", level, "");
	level++;
	printf("calling recursive_sum(%d) and waiting result...\n", n);
	if (n<=0) return n;
	int result = n + recursive_sum(n - 1);
	level--;
	printf("%*s", level, ""); 
	printf("Step %d result: %d\n", n, result);
	return result;
}
int recursive_mul(int n) {
	printf("%*s", level, "");
	level++;
	printf("calling recursive_mul(%d) and waiting result...\n", n);
	if (n<=1) return n;
	int result = n * recursive_mul(n - 1);
	level--;
	printf("%*s", level, ""); 
	printf("Step %d result: %d\n", n, result);
	return result;
}