#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // needed for function atoi()


int main(int argc, char* argv[])
{
	int i, integer;
	char character;
	// atoi() takes a string argument and returns the corresponding integer 
	// or 0 if not recognizable as a number
	// it will even extract an integer from the beginning of a string 
	// (e.g., atoi(4a) will return the integer 4)
	integer = atoi(argv[1]);
	character = argv[2];
	if (argc < 3)
		printf("Usage: %s positive-number\n", argv[0]);
	switch (character) {
		case 's':
			printf("%d's squre is: %d", integer, integer * integer);
			break;
		case 'c':
			printf("%d's squre is: %d", integer, integer * integer * integer);
			break;
		default:
			printf("your second input have to be s or c");
	}
	return 0;
}
