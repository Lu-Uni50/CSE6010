/*
Simple heap implementation using an array with functions
Variables are global to avoid dealing with pointers
Non-recursive heapify functions
*/
#include <stdio.h>
#define MAXHEAPSIZE 20
int HeapInsert(int item);
int HeapDelete();
int PrintHeap();
int HeapifyDown(int i);
int HeapifyUp(int i);

// global variables for heap
int heapSize = 0; // number of elements in heap
int heap[MAXHEAPSIZE];

int main()
{
	int j, valReturned;

	HeapInsert(6);
	HeapInsert(9);
	HeapInsert(3);
	HeapInsert(2);
	HeapInsert(7);
	HeapInsert(4);
	HeapInsert(3);
	HeapInsert(8);

	PrintHeap();

	valReturned = HeapDelete();
	printf("deleted value is = %d\n", valReturned);
	PrintHeap();

	return 0;
}

// function to push an element onto the heap
int HeapInsert(int item)
{
	if (heapSize < MAXHEAPSIZE)  // COMPLETE condition to ensure heap not full
	{
		heap[heapSize] = item;
		HeapifyUp(heapSize);
		heapSize++;
		// COMPLETE body; see lecture notes

		return 0;
	}
	else
	{
		printf("Insertion error; heap is full\n");
		return 1;
	}
}

// function to delete an element from the heap
int HeapDelete()
{
	if (heapSize >= 0)		// COMPLETE condition to ensure heap not empty
	{
		int returnValue;
		returnValue = heap[0];			// COMPLETE

		// COMPLETE remainder of function; see lecture notes
		heap[0] = heap[heapSize - 1];
		heapSize--;
		HeapifyDown(0);
		

		return(returnValue);
	}
	else
	{
		printf("Deletion error; heap is empty\n");
		return -1;
	}
}

// function to print out heap elements
int PrintHeap()
{
	if (heapSize!=0)  // COMPLETE missing condition
	{
		int j;
		printf("heap contents: ");
		for (j = 0; j < heapSize;j++)	// COMPLETE missing loop info
		{
			printf("%d ", heap[j]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		printf("Printing error; heap is empty\n");
		return -1;
	}
}

// Heapify Up function used when inserting
int HeapifyUp(int i)
{
	int temp;
	while (i > 0)
	{
		if (heap[i] < heap[(i-1)/2])	// COMPLETE to test if this node < its parent
		{
			// COMPLETE swap and reset i; see lecture notes
			temp = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = heap[i];
			heap[i] = temp;
			HeapifyUp((i - 1) / 2);
		}
		else
		{
			i = 0; // COMPLETE to ensure while loop terminates
		}
	}
	return 0;

}

// Heapify Down function used when deleting
int HeapifyDown(int i)
{
	int temp;

	while (2 * i + 1 < heapSize) // i has at least one child
	{
		if (heap[2*i+1] != NULL && heap[2 * i + 2] == NULL) // COMPLETE condition to describe that i has only one (left) child
		// note that this case is not detailed in the notes!
		{
			if (heap[i] > heap[2 * i + 1])	// COMPLETE condition that requires a swap
			{

				// COMPLETE appropriate swap between i and its left child
				temp = heap[i];
				heap[i] = heap[2 * i + 1];
				heap[2 * i + 1] = temp;
			}
			i = heapSize; // this will mean i is increased enough to stop while
		}
		else //i has 2 children
		{

			if (heap[i] < heap[2 * i + 1] && heap[i] < heap[2 * i + 2]) // COMPLETE test if heap property is satisfied for i and its 2 children
				i = heapSize; // set i large enough to stop the while loop
			else if (heap[2*i+1]<heap[2*i+2]) 		// COMPLETE; heap property not satisfied + left node < right
			{
				// COMPLETE body; see lecture notes
				temp = heap[i];
				heap[i] = heap[2 * i + 1];
				heap[2 * i + 1] = temp;
				i = 2 * i + 1;
			}
			else								// right node >= left
			{
				// COMPLETE body; see lecture notes
				temp = heap[i];
				heap[i] = heap[2 * i + 2];
				heap[2 * i + 2] = temp;
				i = 2 * i + 2;
			}
		}
	}
	return 0;
}