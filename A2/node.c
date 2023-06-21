#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "node.h"

// initialize the empty listhead
Node *Initialize()
{
    // Allocate memory for new node
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        return NULL;
    }
    // initiate empty node  
    n->next = NULL;
    n->value = 0;
    return n;
}

// insert new node in sorted list
int Insert(Node *listhead, int data)
{
    // verify if the data is positive
    if (data <= 0)
    {
        printf("non-positive input\n");
        return 1;
    }

    Node * current = listhead; // current pointer
    Node* newn = (Node*)malloc(sizeof(Node)); // reuse newn to insert node
    if (newn == NULL)
    {
        printf("failed to malloc\n");
        return 1;
    }   
    // initiate new node
    newn->value = data;
    newn->next = NULL;

    // if the list is empty
    if (current == NULL) 
    {
        newn->next = current;
        current = newn;
        return 0;
    }
    else 
    {
        // iterate till the current pointer points to the right location
        while (current->next != NULL // iterate till the end of the list
               && current->next->value < newn->value)
        {
            current = current->next;
        }
        // insert new node
        newn->next = current->next;
        current->next = newn;
        return 0;
    }
}

// search whether the data is in the list
Node *Search(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        printf("the list is empty\n");
    }

    Node * current = listhead;

    while (current->next != NULL && current->value != data) // iterate the list
    {
      current = current->next;
    }
    if (current->value == data) // find the node->value == data
    {
        return current;
    }
    printf("the data is not in the list.\n");
    return NULL; // if the data is not in the list
}

// delete node
int Delete(Node *listhead, int data)
{
    Node *prt = Search(listhead, data); // location of the del-node
    if (prt == NULL)
    {
        printf("the data is not in the list\n");
        return 1;
    }
    else
    {
        // get the list before node
        Node *before = listhead;
        while (before != NULL && before->next != prt)
        {
            before = before->next;
        }
        before->next = NULL; // delete all nodes after del-node
        before->next = prt->next; // link the 'before' list with the list after del-node
        listhead->next = before;
        return 0;
    }
}

 // find the minimum value in the list
int Minimum(Node *listhead)
{
    Node * current = listhead->next;
    int min = current->value;
    while (current != NULL)
    {
        if (current->value < min)
        {
            min = current->value;
        }
        current = current->next;
    }
    return min;
}

// find the maximum value in the list
int Maximum(Node *listhead)
{
    Node * current = listhead->next;
    int max = current->value;
    while (current != NULL)
    {
        if (current->value > max)
        {
            max = current->value;
        }
        current = current->next;
    }
    return max;
}

// find the predecessor of the input data
int Predecessor(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        printf("the list is empty\n");
        return 1;
    }

    Node *prt = Search(listhead, data);
    if (prt == NULL)
    {
        printf("the data is not in the list\n");
        return 1;
    }
    else if (prt == listhead->next) // the node is the first in the list except the listhead
    {
        printf("the data has no predecessor\n");
        return 1;
    }
    else
    {
        Node *pred = listhead;
        while (pred != NULL && pred->next != prt)
        {
            pred = pred->next;
        }
        return pred->value;
    }
}

// find the successor of the input node
int Successor(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        printf("the list is empty\n");
        return 1;
    }

    Node *prt = Search(listhead, data);
    if (prt == NULL)
    {
        printf("the data is not in the list\n");
        return 1;
    }
    else if (prt->next == NULL) // the node is the last in the list
    {
        printf("the data has no succesor\n");
        return 1;
    }
    else
    {
        return prt->next->value;
    }
}

// return the number of elements in the list
unsigned int Length(Node *listhead)
{
    int counter = 1;
    Node * current = listhead;
    while (current->next != NULL)
    {
        counter++;
        current = current->next;
    }
    return counter;
}

// print all nodes in the list including listhead
void Print(Node *listhead)
{
    if (listhead == NULL)
    {
        printf("NULL");
    }
    else
    {
        while (listhead != NULL) 
        {
            printf("%d", listhead->value);
            listhead = listhead->next;
        }
    }
}

// free memeory
void Finalize(Node *listhead)
{
    Node* tmp;

    while (listhead != NULL)
    {
       tmp = listhead;
       listhead = listhead->next;
       free(tmp);
    }
}

