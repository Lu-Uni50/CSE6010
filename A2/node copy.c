#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "node.h"


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
    return n;
}

int Insert(Node *listhead, int data)
{
    // verify if the data is positive
    if (data <= 0)
    {
        perror("non-positive input\n");
        return 1;
    }

    Node * current = listhead; // current pointer
    Node* newn = (Node*)malloc(sizeof(Node)); // reuse newn to insert node
    if (newn == NULL)
    {
        perror("failed to malloc\n");
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
        // loop till the current pointer points to the right location
        while (current->next != NULL // loop till the end of the list
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

Node *Search(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        perror("the list is empty\n");
    }

    Node * current = listhead;
    // while (current->next != NULL)
    // {
    //     if (current->value == data)
    //     {
    //         return current;
    //     }
    //     current = current->next;
    // }
    // return NULL;

    while (current->next != NULL && current->value != data)
    {
      current = current->next;
    }
    if (current->value == data)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

int Delete(Node *listhead, int data)
{
    Node *prt = Search(listhead, data);
    if (prt == NULL)
    {
        perror("the data is not in the list\n");
        return 1;
    }
    else
    {
        Node *before = listhead;
        while (before != NULL && before->next != prt)
        {
            before = before->next;
        }
        before->next = NULL;
        before->next = prt->next;
        listhead->next = before;
        return 0;
    }
}

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

int Predecessor(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        perror("the list is empty\n");
        return 1;
    }

    Node *prt = Search(listhead, data);
    if (prt == NULL)
    {
        perror("the data is not in the list\n");
        return 1;
    }
    else if (prt == listhead->next)
    {
        perror("the data has no predecessor\n");
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

int Successor(Node *listhead, int data)
{
    if (listhead == NULL)
    {
        perror("the list is empty\n");
        return 1;
    }

    Node *prt = Search(listhead, data);
    if (prt == NULL)
    {
        perror("the data is not in the list\n");
        return 1;
    }
    else if (prt->next == NULL)
    {
        perror("the data has no succesor\n");
        return 1;
    }
    else
    {
        return prt->next->value;
    }
}

unsigned int Length(Node *listhead)
{
    int counter = 1;
    Node * current = listhead->next;
    while (current->next != NULL)
    {
        counter++;
        current = current->next;
    }
    return counter;
}

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

