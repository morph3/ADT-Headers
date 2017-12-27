#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct Node *AVLTree;
struct Node {
    int val;
    AVLTree left;
    AVLTree right;
    int height;
};

AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree InsertElement(int, AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int, int);




#endif _AVLTREE_H
