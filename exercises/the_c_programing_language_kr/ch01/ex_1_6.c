#include <stdio.h>

int main(void) {
	int c = 0;
	while (c = getchar()!=EOF) {
		printf("(getchar()!=EOF) = %d\n", c);
	};
	printf("(getchar()!=EOF) = %d\n", c);
	return 0;
}
