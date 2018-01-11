//
// Created by Melih on 11-Jan-18.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdio.h>
#include <stdlib.h>

//To represent an empty stack, EMPTY_TOS -1 is used
#define EMPTY_TOS -1
#define FALSE 0
#define TRUE 1


struct Node {
    int val;
    struct Node *next;
};


typedef struct Node StackRecord;
typedef StackRecord *Stack;


Stack CreateStack();
void MakeEmptyStack(Stack);
void PushStack(Stack,int);
int PopStack(Stack);
int TopOfStack(Stack);
int IsEmptyStack(Stack);
void DisplayStack(Stack);


#endif //STACK_STACK_H
