#ifndef NODE_H_
#define NODE_H_

typedef struct Node
{
    int value;
    struct Node *next;
}
Node;

Node *Initialize();
int Insert(Node *listhead, int data);
Node *Search(Node *listhead, int data);
int Delete(Node *listhead, int data);
int Minimum(Node *listhead);
int Maximum(Node *listhead);
int Predecessor(Node *listhead, int data);
int Successor(Node *listhead, int data);
unsigned int Length(Node *listhead);
void Print(Node *listhead);
void Finalize(Node *listhead);

#endif