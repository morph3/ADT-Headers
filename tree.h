#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 16
#define FALSE 0
#define TRUE 1

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

typedef struct Node *Tree;

Tree CreateTree(void);
Tree MakeEmptyTree(Tree t);
Tree InsertElement(Tree t,int val);
void DisplayTree(Tree t);
struct Node *newNode(int val);



#endif