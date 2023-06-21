// fun with arrays and pointers 
#include <stdio.h>
int main(void)
{
	int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };

	printf("   zippo = %p,    zippo + 1 = %p\n",
			   zippo,         zippo+1);
	/* 1 line expectation: 
		first: address of the first element of array zippo, a 2 int array, such as '0x...'
		second: add 1 to the address of zippo point to the second element, and because each element in zippo is 2 ints,
				so it is 8 bytes larger than the first element's address.
	*/ 

	printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
	        zippo[0],      zippo[0] + 1);
	/* 2 line expectation:
		first: it is the same as the first line output, the address of the first element of array zippo
		second: zippo[0] + 1 means the pointer points to the next element in zippo[0], which is an int,
				so it is 4 byte larger than the address of zippo[0].
	*/

	printf("  *zippo = %p,   *zippo + 1 = %p\n",
	          *zippo,        *zippo + 1);
	/* 3 line expectation:
		first: it is the same as the first line output.
		second: it is the same as the second line output, which is the address of the array add 1.
	*/
	printf("zippo[0][0] = %d\n", zippo[0][0]);
	/* 4 line expectation:
		it is the first element in the first element in array zippo, which is 2.
	*/
	printf("  *zippo[0] = %d\n", *zippo[0]);
	/* 5 line expectation:
		zippo[0] is the address of array zippo[0]'s first elements,
		so * dereference the address return the value, which is 2.
	*/
	printf("    **zippo = %d\n", **zippo);
	/* 6 line expectation:
		*zippo is the address of zippo[0], second * dereference it to the value of zippo[0][0],
		which is 2.
	*/
	printf("      zippo[2][1] = %d\n", zippo[2][1]);
	/* 7 line expectation:
	zippo[2][1] means zippo's third element's second element, which is 3.
	*/
	printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));
	/* 8 line expectation:
		zippo+2           zippo[0]'s address + 2 == the address of {1,3}
		*(zippo+2)        the address of the first element in zippo+2
		*(zippo+2)+1      the address of the second element in zippo+2
		*(*(zippo+2)+1)   the value of the second element in zippo+2, which is 3
	*/
}

