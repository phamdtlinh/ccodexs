/*
	pldw.c (Palndrome Word)
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {

	if (argc<2) {
		fprintf(stderr, "Usage: %s <word>\n", argv[0]);
		return 1;
	}

	char *p1 = (char*)argv[1];
	char *p2 = p1 + strlen(argv[1]) - 1;
	int palindrome = 1;
	while (p1 < p2) {
		while(p1 < p2 && isspace(*p1)) p1++;
		while(p1 < p2 && isspace(*p2)) p2--;
		if (p1<=p2) {
			printf("P1: %p;value: %d, %c\n", p1, *p1, *p1);
			printf("p2: %p;value: %d, %c\n", p2, *p2, *p2);
			if (*p1 != *p2) {
				palindrome = 0;
				break;
			}
			p1++;
			p2--;
		}
	}
	if (palindrome) {
		printf("This string IS a palindrome!\n");
	} else {
		printf("This string IS NOT a palindrome!\n");
	}

	return 0;
}