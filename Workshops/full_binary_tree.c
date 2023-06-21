/*
Simple tree implementation using an array with functions
Variables are global to avoid dealing with pointers
Non-recursive tree functions
*/
#include <stdio.h>
#define MAXTREESIZE 20
int TreeInsert(int item);
int TreeDelete();
int PrintTree();

// global variables for tree
int treeSize = 0; // number of elements in tree
int tree[MAXTREESIZE];

int main()
{
	int j, valReturned;

	TreeInsert(7);
	PrintTree();
	TreeInsert(1);
	PrintTree();
	TreeInsert(4);
	PrintTree();
	TreeInsert(9);
	PrintTree();
	TreeInsert(2);
	PrintTree();
	TreeInsert(6);

	PrintTree();

	valReturned = TreeDelete();
	printf("deleted value is = %d\n", valReturned);
	PrintTree();

	TreeInsert(5);
	PrintTree();

	valReturned = TreeDelete();
	printf("deleted value is = %d\n", valReturned);
	PrintTree();

	return 0;
}

// function to push an element onto the tree
int TreeInsert(int item)
{
	if (treeSize < MAXTREESIZE)
	{
		if (treeSize > 0) {
			int tempValue = tree[0];
			tree[0] = item;
			treeSize++;
			tree[treeSize - 1] = tempValue;
			return 0;
		}
		else {
			tree[0] = item;
			treeSize++;
			return 0;
		}
	}
	else
	{
		printf("Insertion error; tree is full\n");
		return -1;
	}
}

// function to delete an element from the tree
int TreeDelete()
{
	if (treeSize > 0)
	{
		int returnValue;
		returnValue = tree[treeSize - 1];
		//tree[0] = tree[treeSize - 1];
		treeSize--;
		return(returnValue);
	}
	else
	{
		printf("Deletion error; tree is empty\n");
		return -1;
	}
}


// function to print out tree elements
int PrintTree()
{
	if (treeSize > 0)
	{
		int j;
		printf("tree contents: ");
		for (j = 0; j < treeSize; j++)
		{
			printf("%d ", tree[j]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		printf("Printing error; tree is empty\n");
		return -1;
	}
}
