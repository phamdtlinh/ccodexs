#include <stdio.h>
#include <stdlib.h>

typedef enum bool {
	true = 1,
	false = 0
} bool;

bool isPalindrome(int x);
bool isPalindrome2(int x);
void intToString(int x, char *s, int *s_size);

int main(void) {
	if (isPalindrome(1221)) {
		printf("True\n");
	} else {
		printf("False\n");
	}
	return 0;
}

bool isPalindrome(int x) {
	if (x < 0) return false;

	int original = x;
	long long reverse = 0;
	while (x>0) {
		reverse = reverse * 10 + x % 10;
		x /= 10;
	}
	return reverse == original;
}

// Two pointer
bool isPalindrome2(int x) {
	char s[11] = "0000000000";
	int s_size = 0;
	intToString(x, s, &s_size);
	char *ss = s;
	char *se = ss + s_size - 1;
	while (se>ss) {
		printf("s1 (%c): %p, e1 (%c): %p\n", *ss, ss, *se, se);
		if (*se != *ss) return false;
		se--;
		ss++;
	}
	return true;
}

void intToString(int x, char *s, int *s_size) {
	int remain = 0;
	int div_result = 0;
	int i = 0;
	div_result = x;
	if (div_result< 0) div_result *= -1;
	do {
		remain = div_result % 10;
		s[i] = remain + '0';
		printf("%d\n", remain);
		i++;
	} while ((div_result = (div_result / 10)));
	s[i] = '\0';
	*s_size = i;
}