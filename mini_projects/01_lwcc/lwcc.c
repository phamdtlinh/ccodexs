/*
	lwcc.c (lines, words, chars counter)
*/

#include <stdio.h>
#include <ctype.h>

typedef enum Switcher {
	ON = 1,
	OFF = 0
} Switcher;

int main(int argc, char **argv) {
	FILE *fp = NULL;
	int c;
	int char_count = 0, word_count = 0, line_count = 0;
	Switcher word_state = OFF;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "r");
	if (!fp) {
		fprintf(stderr, "Failed to open: %s\n", argv[1]);
		return 1;
	}

	while((c = fgetc(fp)) != EOF) {
		if (!isspace(c)) {
			if (!word_state) word_count++;
			word_state = ON;
		} else {
			word_state = OFF;
		}
		if (c == '\n') {
			line_count++;
		}
		char_count++;
	}

	printf("Line(s): %d, Word(s): %d, Char(s): %d\n",
			line_count, word_count, char_count);
	fclose(fp);
	return 0;
}
