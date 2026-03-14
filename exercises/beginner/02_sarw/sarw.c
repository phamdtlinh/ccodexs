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
	size_t sslen = strlen(argv[2]);
	size_t rslen = strlen(argv[3]);
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
				fclose(fp);
				line_buffer = NULL;
				fp = NULL;
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
				p += sslen;
			}
			if (found_count) {
				size_t result_capacity = buff_index + 1;
				int sr_diff = rslen - sslen;
				if (sr_diff > 0) {
					result_capacity += sr_diff*found_count;
				}
				char *result_buffer = malloc(result_capacity);
				if (!result_buffer) {
					fprintf(stderr, "result_buffer malloc failed\n");
					free(line_buffer);
					fclose(fp);
					line_buffer = NULL;
					fp = NULL;
					return 1;
				}
				char *lbp1 = line_buffer; //lb = line buffer
				char *lbp2 = line_buffer;
				char *rbp1 = result_buffer; // rb = result buffer
				while ((lbp2 = strstr(lbp2, argv[2]))) {
					size_t copy_size = lbp2 - lbp1;
					rbp1 = memcpy(rbp1, lbp1, copy_size);
					rbp1 += copy_size;
					rbp1 = memcpy(rbp1, argv[3], rslen);
					rbp1 += rslen;
					lbp2 += sslen;
					lbp1 = lbp2;
				}
				strcpy(rbp1, lbp1);
				printf("Found \"%s\" %d times in below string (need to replace):\n%s",
						argv[2], found_count, line_buffer);
				printf("Replaced:\n%s\n\n", result_buffer);
				free(result_buffer);
				result_buffer = NULL;
			}
			buff_index = 0;
		}

		if (c == EOF) {
			break;
		}
	}

	free(line_buffer);
	fclose(fp);
	line_buffer = NULL;
	fp = NULL;
	return 0;
}
