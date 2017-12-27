#include "AVLTree.h"

AVLTree CreateTree(void) {
    return NULL;
}

AVLTree MakeEmptyTree(AVLTree t) {
    if (t != NULL)
    {
        MakeEmptyTree(t->left);
        MakeEmptyTree(t->right);
        free(t);
    }
    return NULL;
}

AVLTree InsertElement(int val, AVLTree t) {
    if (t == NULL) {
        /*Create and return a one-node tree */
        t = (struct Node *)malloc(sizeof(struct Node));
        if (t == NULL){
            printf("Could not allocate!\n");
        }
        else {
            t->val = val;
            t->height = 0;
            t->left = NULL;
            t->right = NULL;
        }
    }
    else if (val<t->val) {
        t->left = InsertElement(val, t->left);
        if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
            if (val < t->left->val)
                t = SingleRotateWithLeft(t);
            else
                t = DoubleRotateWithLeft(t);
    }
    else if (val > t->val)
    {
        t->right = InsertElement(val, t->right);
        if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
            if (val > t->right->val)
                t = SingleRotateWithRight(t);
            else
                t = DoubleRotateWithRight(t);
    }
    /* else val is in the tree already ... do nothing */
    t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;

    return t;
}

void DisplayTree(AVLTree t)
{
    if (t != NULL)
    {
        DisplayTree(t->left);
        printf("%d\n", t->val);
        DisplayTree(t->right);
    }
}

void DisplayTreeStructure(AVLTree t, int depth)
{
    int i;

    if (t != NULL)
    {
        DisplayTreeStructure(t->right, depth + 1);

        for (i = 0; i < depth; i++)
            printf("     ");
        printf("%d\n", t->val);

        DisplayTreeStructure(t->left, depth + 1);
    }
}

int AVLTreeHeight(AVLTree t)
{
    if (t == NULL)
        return -1;
    else
        return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    //TO BE COMPLETED!
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
    //TO BE COMPLETED!
}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
    //TO BE COMPLETED!
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
    //TO BE COMPLETED!
}

int Max(int x, int y) {
    if (x >= y)
        return x;
    else{
        return y;
    }
}