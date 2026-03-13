/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal;
a vertical orientation is more challenging. 
*/

#include <stdio.h>

#define WORD_MAX_LENGTH 50

typedef enum Switcher Switcher;
enum Switcher {
	ON = 1,
	OFF = 0
};

int mispace(int c);
int min_index(int arr[], int size);
int max_index(int arr[], int size);

int main(void) {
	Switcher word_state = OFF;
	int word_count = 0;
	int c;
	int histogram[WORD_MAX_LENGTH] = {0};
	int char_count = 0;
	while ((c = getchar()) != EOF)
	{
		if (mispace(c)) {
			if (char_count < WORD_MAX_LENGTH && char_count != 0) histogram[char_count]++;
			word_state = OFF;
			char_count = 0;
		} else {
			if (!word_state) {
				word_state = ON;
				word_count++;
			}
			char_count++;
		}
	}

	// horizontal histogram
	printf("Word count: %d\n", word_count);
	int check_word_count = 0;
	for (int i = 0; i < WORD_MAX_LENGTH; i++) {
		if (histogram[i] > 0) {
			printf("%2d char(s) words: ", i);
			for (int j = 0; j < histogram[i]; j++) {
				printf("*");
			}
			printf(" (%d)\n", histogram[i]);
			check_word_count += histogram[i];
		}
	}
	printf("Recheck word_count: %d\n", check_word_count);

	// vertical histogram
	printf("\n\nVERTICAL HISTOGRAM:\n");
	for (int i = histogram[max_index(histogram, WORD_MAX_LENGTH)]; i > 0; i--) {
		for (int j = 1; j < WORD_MAX_LENGTH; j++) {
			if (histogram[j]>=i) {
				printf(" *  |");
			} else {
				if (histogram[j] > 0) {
					printf("    |");
				}
			}
		}
		printf("\n");
	}
	for (int i = 0; i < WORD_MAX_LENGTH; i++) {
		if (histogram[i] > 0) {
			printf("-----");
		}
	}
	printf("\n");
	for (int i = 0; i < WORD_MAX_LENGTH; i++) {
		if (histogram[i] > 0) {
			printf("%2d c", i);
			printf ("|");
		}
	}
	printf("\n");
	for (int i = 0; i < WORD_MAX_LENGTH; i++) {
		if (histogram[i] > 0) {
			printf("  %2d", histogram[i]);
			printf ("|");
		}
	}
	printf("\n");

	return 0;
}
int mispace(int c) {
	return (c == ' ' || c == '\t' || c == '\n');
}

int min_index(int arr[], int size) {
	if (!arr || size <= 0) return -1;
	int index = 0;
	int min = WORD_MAX_LENGTH;
	for (int i = 1; i < size; i++) {
		if (arr[i]>0) {
			if (min > arr[i]) {
				index = i;
				min = arr[index];
			}
		}
	}
	return index;
}
int max_index(int arr[], int size) {
	if (!arr || size <= 0) return -1;
	int index = 0;
	int max = arr[index];
	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			index = i;
			max = arr[index];
		}
		
	}
	return index;
}
