#include <stdio.h>

int main(void) {
	int blank_count = 0;
	int tab_count = 0;
	int newline_count = 0;
	int c = -1;
	while ((c = getchar()) != EOF) {
		if (c == ' ') blank_count++;
		if (c == '\t') tab_count++;
		if (c == '\n') newline_count++; 
	}
	printf("Blank count: %d\n", blank_count);
	printf("Tab count: %d\n", tab_count);
	printf("Newline count: %d\n", newline_count);
	return 0;
}
