#include <stdio.h>
//TODO: fix this logic
int main(void) {
	int c = -1;
	int prev_c = -1;
	while ((c = getchar()) != EOF) {
		if ((prev_c != -1 && prev_c != ' ') || c != ' ') {
			printf("%c", c);
		}
		if (c == ' ' && prev_c != ' ') {
			printf("\n");
		}
		prev_c = c;
	}
	return 0;
}
