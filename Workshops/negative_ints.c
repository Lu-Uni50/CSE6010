/*
	program to take a 4-bit binary integer and return negative representations
	treat them as character strings
*/
#include <stdio.h>
#include <math.h>
#define NBITS 4
int PrintBitString(char someint[NBITS]);

int main()
{

	// initialize
	char myint[NBITS] = "0011";

	printf("original bit string: ");
	PrintBitString(myint);

	// find signmagnitude
	char signmagnitude[NBITS] = "0000";
	if (myint[0] == '0')
		signmagnitude[0] = '1';
	else
		signmagnitude[0] = '0';
	for (int j = 1; j < NBITS; j++)
	{
		signmagnitude[j] = myint[j];
	}
	printf("sign magnitude bit string: ");
	PrintBitString(signmagnitude);

	printf("One's complement representation: ");
	for (int j = 1; j < NBITS; j++)
	{
		if (signmagnitude[j] == '0') {
			signmagnitude[j] = '1';
		}
		else {
			signmagnitude[j] = '0';
		}
	}
	PrintBitString(signmagnitude);

	int sum = 0;
	int i = 0;
	for (int j = NBITS-1; j >= 0; j--) {
		if (signmagnitude[j] == '0' && j != 0)
			sum += 1*pow(2, i);
		else if(j == 0 && signmagnitude[0] == '1') {
			sum = 0 - sum;
		}
		i++;
	}
	printf("One's complement representation to integer: %d\n",sum);

	printf("Two's complement representation: ");
	signmagnitude[NBITS - 1] = '1';
	PrintBitString(signmagnitude);

	sum = 0;
	i = 0;
	for (int j = NBITS - 1; j >= 0; j--) {
		if (signmagnitude[j] == '1' && j != 0)
			sum += 1 * pow(2, i);
		else if (j == 0 && signmagnitude[0] == '1') {
			sum -= 1 * pow(2, i);
		}
		i++;
	}
	printf("Two's complement representation to integer: %d\n", sum);

	
		

	return 0;
}

int PrintBitString(char someint[NBITS])
{
	for (int j = 0; j < NBITS; j++)
		printf("%c", someint[j]);
	printf("\n");
}
