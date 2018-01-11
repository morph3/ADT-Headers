#include "Stack.h"

//This function initialises a stack with a dummy node
Stack CreateStack() {
    Stack myStack = (struct Node*)malloc(sizeof(struct Node));
    myStack->next = NULL;
    if(myStack == NULL){
        printf("Error , could not allocate memory\n");
    }
    return myStack;
}

//This function empties the content of a stack
void MakeEmptyStack(Stack s) {

}

//This function checks if a stack is empty or not
int IsEmptyStack(Stack s) {
    return (s->next == NULL);
}

//This function checks if a stack is full
int IsFullStack(Stack s)
{
    return FALSE;
}

//This function creates a new node, adds the value of x to this node
//and then pushes this new node to the given stack
void PushStack(Stack s , int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Error , could not allocate memory");
    }
    else{
        newNode->val = data;
        newNode->next = s->next;
        s->next = newNode;
    }
}


int PopStack(Stack s){
    struct Node* removeNode = (struct Node*)malloc(sizeof(struct Node));
    int value;
    if(s == NULL){
        printf("Eror , stack is empty \n");
    }
    else{
        // There is a dummy node at the beginning
        // so we have to assign it to stacks next
        removeNode = s->next;
        s->next = s->next->next;
        value = removeNode->val;
        free(removeNode);
    }
    return value;
}

//This function returns the value stored at the top node
int TopOfStack(Stack s) {
    if(s != NULL){
        return s->val;
    }
    else{
        printf("Error , stack is empty ");
        return -1;
    }

}

//This function displays the content of a stack
void DisplayStack(Stack s) {
    struct Node *p;
    printf("Stack content:\n");
    if (IsEmptyStack(s))
        printf("The stack is empty!\n");
    else{
        p = s->next;
        while (p != NULL)
        {
            printf("\t--> %d\n", p->val);
            p = p->next;
        }
    }
}