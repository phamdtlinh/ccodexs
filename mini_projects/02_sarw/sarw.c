/*
	sarw.c (search and replace word)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LINE_BUFFER_INIT_CAPACITY 1024
#define LINE_BUFFER_GROW 2

typedef enum Switcher {
	ON = 1,
	OFF = 0
} Switcher;

int main(int argc, char **argv) {
	FILE *fp = NULL;
	int c;
	// Switcher word_state = OFF;
	size_t line_buffer_capacity = LINE_BUFFER_INIT_CAPACITY;
	char *line_buffer = NULL;
	size_t buff_index = 0;
	if (argc < 4) {
		fprintf(stderr, "Usage: %s <filename> <search> <replace>\n", argv[0]);
		return 1;
	}

	fp = fopen(argv[1], "r");
	if (!fp) {
		fprintf(stderr, "Failed to open: %s\n", argv[1]);
		return 1;
	}
	line_buffer_capacity = LINE_BUFFER_INIT_CAPACITY * sizeof(*line_buffer);
	line_buffer = malloc(line_buffer_capacity);
	if (!line_buffer) {
		fprintf(stderr, "line_buffer malloc failed!\n");
		return 1;
	}


	while((c = fgetc(fp))) {
		if (buff_index == line_buffer_capacity) {
			size_t new_capacity = line_buffer_capacity * LINE_BUFFER_GROW;
			char *tmp = realloc(line_buffer, new_capacity);
			if (!tmp) {
				fprintf(stderr, "line_buffer realloc failed\n");
				free(line_buffer);
				line_buffer = NULL;
				return 1;
			}
			line_buffer = tmp;
			line_buffer_capacity = new_capacity;
		}
		if (c != EOF) {
			line_buffer[buff_index] = c;
			buff_index++;
		}
		if (c == '\n' || c == EOF) {
			line_buffer[buff_index] = '\0';
			char *p = line_buffer;
			int found_count = 0;
			while ((p = strstr(p, argv[2]))) {
				found_count++;
				p += strlen(argv[2]);
			}
			if (found_count) {
				// TODO: logic replace here
				printf("Found \"%s\" %d times in below string (need to replace):\n%s\n", argv[2], found_count, line_buffer);
			}
			buff_index = 0;
		}

		if (c == EOF) {
			break;
		}
	}

	free(line_buffer);
	line_buffer = NULL;
	fclose(fp);
	fp = NULL;
	return 0;
}
