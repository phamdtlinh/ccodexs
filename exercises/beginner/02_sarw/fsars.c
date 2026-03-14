/*
	fsars.c (file search and replace string)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_INIT_CAPACITY 1024*512
#define BUFFER_GROW_FACTOR 2
#define BUFFER_READ_MAX_SIZE 1024

void *mrealloc(void *ptr, size_t new_capacity);

int main(int argc, char **argv) {

	if (argc<3) {
		fprintf(stderr, "Usage: <str to search> <str to replace> [input file] [output file]\n");
		fprintf(stderr, "[input file] and [output file] are optional\n");
		return 1;
	}

	size_t sslen = strlen(argv[1]);
	size_t rslen = strlen(argv[2]);
	FILE *input_ptr = stdin;
	size_t buffer_current_capacity = BUFFER_INIT_CAPACITY + BUFFER_READ_MAX_SIZE;
	size_t buffer_index = 0;
	char *buffer = malloc(BUFFER_INIT_CAPACITY * sizeof(*buffer));
	if (!buffer) {
		fprintf(stderr, "buffer malloc failed!\n");
		return 1;
	}

	char *buffer_ptr = buffer;
	char *buffer_ptr_search = buffer;
	int found_count = 0;
	while (1) {
		if ((buffer_index + BUFFER_READ_MAX_SIZE) >= buffer_current_capacity) {
			size_t new_capacity = buffer_current_capacity * BUFFER_GROW_FACTOR + BUFFER_READ_MAX_SIZE;
			char *tmp = realloc(buffer, new_capacity);
			if (!tmp) {
				fprintf(stderr, "buffer realloc failed!\n");
				free(buffer);
				buffer = NULL;
				return 1;
			}
			buffer = tmp;
			buffer_current_capacity = new_capacity;
			buffer_ptr = buffer + buffer_index;
		}
		size_t read_char = 0;
		read_char = fread(buffer_ptr, sizeof(*buffer), BUFFER_READ_MAX_SIZE, input_ptr);
		if (!read_char) break;
		buffer_ptr_search = buffer_ptr;
		buffer_ptr += read_char;
		buffer_index += read_char;
		buffer[buffer_index] = '\0';
		while ((buffer_ptr_search = strstr(buffer_ptr_search, argv[1]))) {
			found_count++;
			printf("%d\n", found_count);
			buffer_ptr_search += sslen;
		}
	}
	buffer[buffer_index] = '\0';

	printf("Found \"%s\" %d time(s)\n%zu %zu\n", argv[1], found_count, strlen(buffer), (buffer + buffer_index) - buffer);
	printf("%s\n", buffer);

	return 0;
}
