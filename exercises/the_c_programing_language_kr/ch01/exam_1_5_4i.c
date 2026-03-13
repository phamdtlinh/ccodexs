// exam_1_5_4i: i for improved

#include <stdio.h>

int main(void) {

	int c;
	int c_count = 0, w_count = 0, l_count = 0;
	int prev_char = -1;
	while ((c = getchar()) != EOF) {
		if ((prev_char == -1) && (c != ' ' && c != '\n' && c != '\t')) w_count++;
		if (prev_char == '\n' || prev_char == -1) l_count++;
		if ((c == ' ' || c == '\n' || c == '\t') &&
			(prev_char != ' ' && prev_char != '\n' && prev_char != '\t')) {
			w_count++;
		}
		prev_char = c;
		if (c != '\n' && c != '\t') c_count++;
	}
	if (prev_char == ' ' || prev_char == '\n' || prev_char == '\t') {
		w_count--;
	}
	printf("Character(s) count: %d\nWord(s) count: %d\nLine(s) count: %d\n", c_count, w_count, l_count);

	return 0;
}
/* Refined below:
#include <stdio.h>

typedef enum Switcher Switcher;
enum Switcher {
	ON = 1,
	OFF = 0
};

int mispace(int c);

int main(void) {
	Switcher word_state = OFF;
	int word_count = 0;
	int c;
	while ((c = getchar()) != EOF)
	{
		if (mispace(c)) {
			word_state = OFF;
		} else if (!word_state) {
			word_state = ON;
			word_count++;
		}
	}

	printf("Word count: %d\n", word_count);

	return 0;
}
int mispace(int c) {
	return (c == ' ' || c == '\t' || c == '\n');
}
*/

/*

TODO: Refine the code

Explaination some line:
Line 1:		Standard input/output library

Line 3:		Entry point start

Line 5 - 7:	Variables decelerations
Line 8:		Read char by char from keyboard via terminal (shell) as long as it is NOT EOF (Ctrl-D, once, sometime twice)
Line 9-16:	Main logic
Line 18-20:	Decrease the last count of word
Line 21:	Print the results

Line 23:	exit program without error
Line 24:	Entry point end

There is no detail explaination for each line by the end of Chapter 1
*/
