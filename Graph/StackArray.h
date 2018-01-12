#pragma once
#include <stdio.h>
#include <stdlib.h>

//To represent an empty stack, EMPTY_TOS -1 is used
#define EMPTY_TOS -1 
//Minimim stack size should be 5
#define MIN_STACK_SIZE 9
#define FALSE 0
#define TRUE 1

#define MAXIMUM_VERTICES 9
//Stack record that holds the following data:
//the capacity of the stack, 
//the index of the top of stack and 
//the array to hold the data in the stack

struct StackRecord {
	int capacity;
	int topOfStack;
	struct graphVertex *vertexArray[MAXIMUM_VERTICES];
};
typedef struct StackRecord *Stack;

//Function signatures
Stack CreateStack(int);
void MakeEmptyStack(Stack);
void PushStack(Stack s, struct graphVertex *vertex);
struct graphVertex* PopStack(Stack s);
struct graphVertex* TopOfStack(Stack s);
int IsFullStack(Stack);
int IsEmptyStack(Stack);
void DisplayStack(Stack);

