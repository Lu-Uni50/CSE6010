// fun with arrays and pointers 
#include <stdio.h>
int main(void)
{
	int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
	/* To declare a pointer variable that can point to a two-dimensional array
		like zippo, we must use a pointer that points to an array of two ints, 
		not to a single int. 
		We instead use int (*pz)[2]: 
		pz is a pointer to an array of 2-ints.
		Parentheses are needed because [] has a higher precedence than *
	*/
	
	int (*pz)[2];
	pz = zippo; // don't forget to assign the pointer pz a value!

	/* In general you can represent individual elements by using array notation 
		or pointer notation with either an array name or a pointer
			zippo[m][n] == *(*(zippo + m) + n)
			pz[m][n] 	== *(*(   pz + m) + n)
	
	*/
	
	printf("   pz = %p,    pz + 1 = %p\n",
			   pz,         pz+1);
	/* 1 expectation:
		pz: address of the first 2-int element in zippo.
		pz+1: address of the second 2-int element in zippo.
	*/
	printf("pz[0] = %p, pz[0] + 1 = %p\n",
	        pz[0],      pz[0] + 1);
	/* 2 expectation:
		pz[0]: address of the first 2-int element in zippo.
		pz[0]+1: address of the second int in the first 2-int element in zippo
	*/
	printf("  *pz = %p,   *pz + 1 = %p\n",
	          *pz,        *pz + 1);
	/* 3 expectation:
		*pz: address of the zippo[0], the same as the first line.
		*pz+1: address of the second element in zippo[0].
	*/
	printf("pz[0][0] = %d\n", pz[0][0]);
	/* 4 expectation:
		pz[0][0], first element in the first element in zippo, which is 2.
	*/
	printf("  *pz[0] = %d\n", *pz[0]);
	/* 5 expectation:
		dereference the address of pz[0], which is the value of pz[0][0], which is 2
	*/
	printf("    **pz = %d\n", **pz);
	/* 6 expectation:
		*pz is the address of pz[0]
		**pz is dereference the address of pz[0][0], which is value 2.
	*/
	printf("      pz[2][1] = %d\n", pz[2][1]);
	/* 7 expectation:
		pz[2][1] is the third element's second element, which is 3.
	*/
	printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));
	/* 8 expectation
		pz             the address of pz[0]
		pz+2           the address of pz[2]
		*(pz+2)        the address of pz[2][0]
		*(pz+2) + 1    the address of pz[2][1]
		*(*(pz+2)+1)   dereference the address of pz[2][1], which is 3.
	*/
}

