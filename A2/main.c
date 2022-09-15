#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main(void)
{
    Node *listhead = Initialize();
    Insert(listhead, 1);
    Insert(listhead, 4);
    Insert(listhead, 3);
    Insert(listhead, 2);
    Print(listhead);

    printf("\n");

    Node *p = Search(listhead, 3);
    printf("%p\n", p);
    // Delete(listhead, 2);
    // Print(listhead);

    // int max = Maximum(listhead);
    // printf("%i\n", max);
    // int min = Minimum(listhead);
    // printf("%i\n", min);

    // int pred = Predecessor(listhead, 3);
    // printf("%i\n", pred);
    // int suc = Successor(listhead, 3);
    // printf("%i\n", suc);

    // int counter = Length(listhead);
    // printf("%i\n", counter);

    // Finalize(listhead);
}