#include <stdio.h>

int main(void) {
	int c = -1;
	while ((c = getchar()) != EOF) {
			if (c == '\t') {
				printf("\\t");
			} else if (c == '\n') {
				printf("\\n");
			} else if (c == '\b') {
				printf("\\b");
			} else {
				printf("%c", c);
			}
	}
	printf("\n");
	return 0;
}
