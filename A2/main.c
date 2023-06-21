#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main(void)
{
    // test codes

    // initialize list head - dummy
    Node *listhead = Initialize();


    // insert numbers
    Insert(listhead, 1);
    Insert(listhead, 4);
    Insert(listhead, 3);
    Insert(listhead, 2);
    Print(listhead);
    printf("\n");
    // error case test
    Insert(listhead, -1);
    printf("\n");


    // search
    Node *p = Search(listhead, 3);
    printf("result of search: %p\n", p);
    // error case test
    Node *pt = Search(listhead, 6);


    // delete
    Delete(listhead, 2);
    Print(listhead);
    printf("\n");


    // max and min
    int max = Maximum(listhead);
    printf("the max node in the list: %i\n", max);
    int min = Minimum(listhead);
    printf("the min node in the list: %i\n", min);


    // predecessor and successor
    int pred = Predecessor(listhead, 3);
    printf("the predecessor: %i\n", pred);
    int suc = Successor(listhead, 3);
    printf("the successor: %i\n", suc);
    // error case test
    int predt = Predecessor(listhead, 1);
    int suct = Successor(listhead, 4);


    // length of the list
    int counter = Length(listhead);
    printf("the length of the list: %i\n", counter);

    // finalize and free all nodes
    Finalize(listhead);
}