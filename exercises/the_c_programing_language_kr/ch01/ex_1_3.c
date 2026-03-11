#include <stdio.h>

int main(void) {

	int c;
	int char_count = 0;
	int word_count = 0;
	int line_count = 0;
	int is_space = 0;
	while ((c = getchar()) != EOF) {
		if (c=='\n') line_count++;
		if (c == ' ' && !is_space) {
			word_count++;
			is_space = 1;
		} else if (c != ' ') {
			is_space = 0;
		}
		char_count++;
	}
	if (char_count>0) word_count++;
	printf("Character(s) count: %d\nWord(s) count: %d\nLine(s) count: %d\n", char_count, word_count, line_count);

	return 0;
}

/*

TODO: Refine the code

Explaination some line:
Line 1:		Standard input/output library

Line 3:		Entry point start

Line 5 - 9:	Variables decelerations
Line 10:	Read char by char from keyboard via terminal (shell) as long as it is NOT EOF (Ctrl-D, once, sometime twice)
Line 11-18:	Increase variables
Line 20:	Increase variable word_count
Line 21:	Print the results

Line 23:	exit program without error
Line 24:	Entry point end

There is no detail explaination for each line by the end of Chapter 1
*/