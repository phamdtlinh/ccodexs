#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void xorswap(char *s, char *e) {
	if (s!=e) {
		*s = *s ^ *e;
		*e = *s ^ *e;
		*s = *s ^ *e;
	}
} 
int main(int argc, char **argv) {

	if (argc<2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		return 1;
	}

	size_t slen = strlen(argv[1]);
	char *s_mirror = malloc(slen + 1);
	if (!s_mirror) {
		fprintf(stderr, "s_mirror malloc failed!\n");
		return 1;
	}
	strcpy(s_mirror, argv[1]);
	char *s_start = s_mirror;
	char *s_end = s_start + strlen(s_mirror) - 1;
	if (s_end>s_start) {
		printf("s_e (%c) - s_s (%c) = %ld\n", *s_end, *s_start, s_end - s_start);
	}

	while ((s_end>s_start) && isspace(*s_start)) s_start++;
	while ((s_end>s_start) && isspace(*s_end)) s_end--;
	while (s_end>s_start) {
		xorswap(s_start, s_end);
		s_start++;
		s_end--;
	}
	printf("Original: %s\n", argv[1]);
	printf("Reversed Char: %s\n", s_mirror);
	s_start = s_mirror;
	s_end = s_start + strlen(s_mirror) - 1;
	char *w_start = s_mirror;
	char *w_end = s_mirror;
	while(w_end<s_mirror) {
		if (isspace(w_end)) {
			while(w_start<w_end) {
				xorswap(w_start, w_end);
				w_start++;
			}
		}
		w_end++;
	}
	printf("Reversed Word: %s\n", s_mirror);
	free(s_mirror);
	s_mirror = NULL;
	return 0;
}

