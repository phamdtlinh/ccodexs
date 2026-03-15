/*
	fsars.c (file search and replace string)
	!!!!!!CAUTION!!!!!!
	Destination file will be overwritten if existed
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
	size_t buffer_current_capacity = BUFFER_INIT_CAPACITY + 1;
	size_t total_read = 0;
	char *buffer = malloc(buffer_current_capacity * sizeof(*buffer));
	if (!buffer) {
		fprintf(stderr, "buffer malloc failed!\n");
		return 1;
	}

	FILE *fp = NULL;
	if (argc > 3) {
		fp = fopen(argv[3], "rb");
		if (!fp) {
			fprintf(stderr, "fopen failed, use stdin instead\n");
		} else {
			input_ptr = fp;
		}
	}

	char *buffer_ptr = buffer;
	char *buffer_ptr_search = buffer;
	int found_count = 0;
	while (1) {
		if ((total_read + BUFFER_READ_MAX_SIZE) >= buffer_current_capacity) {
			size_t new_capacity = buffer_current_capacity * BUFFER_GROW_FACTOR;
			char *tmp = realloc(buffer, new_capacity);
			if (!tmp) {
				fprintf(stderr, "buffer realloc failed!\n");
				free(buffer);
				fclose(fp);
				fp = NULL;
				buffer = NULL;
				return 1;
			}
			buffer = tmp;
			buffer_current_capacity = new_capacity;
			buffer_ptr = buffer + total_read;
		}
		size_t read_char = 0;
		read_char = fread(buffer_ptr, sizeof(*buffer), BUFFER_READ_MAX_SIZE, input_ptr);
		if (!read_char) break;
		buffer_ptr += read_char;
		total_read += read_char;
	}
	buffer[total_read] = '\0';
	buffer_ptr_search = buffer;
	while ((buffer_ptr_search = strstr(buffer_ptr_search, argv[1])) != NULL) {
		found_count++;
		buffer_ptr_search += sslen;
	}
	char *result_buffer = NULL;
	if (found_count > 0) {
		int result_diff = (rslen - sslen) * found_count;
		size_t result_capacity = total_read + result_diff;
		if (result_diff > 0) {
			result_capacity = total_read + result_diff * sizeof(*buffer);
		}
		result_buffer = malloc(result_capacity + 1);
		if (!result_buffer) {
			free(buffer);
			fclose(fp);
			fp = NULL;
			buffer = NULL;
			return 1;
		}
		char *bpt1 = buffer, *bpt2 = buffer;
		char *rbt1 = result_buffer;
		while ((bpt2 = strstr(bpt2, argv[1])) != NULL) {
			size_t copy_len = bpt2 - bpt1;
			memcpy(rbt1, bpt1, copy_len);
			rbt1 += copy_len;
			memcpy(rbt1, argv[2], rslen);
			rbt1 += rslen;
			bpt2 += sslen;
			bpt1 = bpt2;
		}
		bpt2 = buffer + total_read;
		size_t last_copy_len = bpt2 - bpt1;
		memcpy(rbt1, bpt1, last_copy_len);
		result_buffer[result_capacity] = '\0';
	}
	
	int write_to_output_file = 0;
	if (argc>4) {
		fclose(fp);
		fp = NULL;
		fp = fopen(argv[4], "w");
		if (!fp) {
			fprintf(stderr, "fopen failed, printf out instead!");
		} else {
			fprintf(fp, "Original:\n%s\n", buffer);
			fprintf(fp, "Found \"%s\" %d time(s)\n", argv[1], found_count);
			if (result_buffer) {
				fprintf(fp, "Result:\n%s\n", result_buffer);
			}
			write_to_output_file = 1;
		}
	}
	if (!write_to_output_file) {
		printf("Original:\n%s\n", buffer);
		printf("Found \"%s\" %d time(s)\n", argv[1], found_count);
		if (result_buffer) {
			printf("Result:\n%s", result_buffer);
		}
	}
	free(result_buffer);
	if (fp) {
		fclose(fp);
		fp = NULL;
	}
	free(buffer);
	result_buffer = NULL;
	buffer = NULL;
	return 0;
}
