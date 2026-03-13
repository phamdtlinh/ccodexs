#include <stdio.h>

int main(void) {
	int c = -1;
	int prev_c = -1;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || ((prev_c != -1) && prev_c != ' ')) {
			printf("%c", c);
		}
		prev_c = c;
	}
	return 0;
}
