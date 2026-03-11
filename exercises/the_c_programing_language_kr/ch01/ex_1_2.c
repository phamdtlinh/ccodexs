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

/*
Explaination each line:
Line 1:		Standard input/output library

Line 3-5:	Precompile code to define the constants

Line 7:		Entry point start

Line 9:		print the header
Line 10:	for loop start
Line 11:	calculate the fahrenheit value for each loop step
Line 12:	print the result
Line 13:	Loop end, repeat if celsius <= UPPER, exit if NOT
Line 14:	print the foooter

Line 16:	exit program without error
Line 17:	Entry point end

There is no detail explaination for each line by the end of Chapter 1
*/