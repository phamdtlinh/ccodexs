#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void) {
	
	printf(" --Celsius--|--Fahrenheit-- \n");
	for (int celsius = LOWER; celsius <= UPPER; celsius += STEP) {
		float fahrenheit = celsius * 1.8f + 32.0f;
		printf("|  %-8d |  %-11.1f |\n", celsius, fahrenheit);
	}
	printf(" -------------------------- \n");

	return 0;
}
