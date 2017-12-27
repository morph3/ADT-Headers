#include "Tree.h"

Tree CreateTree(void) {
    return NULL;
}

/*Function that takes a tree and makes it an empty tree by removing all the nodes from that tree*/
Tree MakeEmptyTree(Tree t) {
    if (t != NULL){
        MakeEmptyTree(t->left);
        MakeEmptyTree(t->right);
        free(t);
    }
    return NULL;
}

/*This function takes an integer value and a tree,
  and inserts that value to the tree*/
Tree InsertElement(Tree t,int val) {

    if(t == NULL){
        return newNode(val);
    }
    if(val < t->val){
        t->left = InsertElement(t->left, val);
    }
    else if(val > t->val){
        t->right = InsertElement(t->right, val);
    }
    return t;
}

/*This function takes a tree and displays its content on the screen*/
void DisplayTree(Tree t) {

    // inorder display
    if (t){
        DisplayTree(t->left);
        printf("%d\n", t->val);
        DisplayTree(t->right);
    }
}

struct Node *newNode(int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Could not allocate memory");
    }
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}

