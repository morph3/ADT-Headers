#include "StackArray.h"
//This function initialises a stack by initialising the following:
//Initiliases the array that will hold the data
//Sets the capatity to the maximum number of elements
//Calls the makeEmptyStack function to initialise the top of stack to -1
Stack CreateStack(int maxElements){
	Stack s;
	if (maxElements < MIN_STACK_SIZE) printf("Stack size is too small");
	
	s = (Stack)malloc(sizeof(struct StackRecord));
	
	if (s == NULL) printf("Error could not allocate");
		
	if (s->vertexArray == NULL) printf("Error , could not allocate");
	s->capacity = maxElements;
	MakeEmptyStack(s);
	return s;
}

//Sets the top of stack to -1 which represents an empty stack
void MakeEmptyStack(Stack s){
	s->topOfStack = -1;
}

//Checks if a stack is empty. If the top of stack is -1 then the stack is empty.
int IsEmptyStack(Stack s){
	return(s->topOfStack == -1);
}

//Checks if a stack is full, if the top of stack is equal to the capacity then the stack is full
int IsFullStack(Stack s){
	return(s->topOfStack == s->capacity);

}

//Pushes the given element to the stack and increments the top of stack
void PushStack(Stack s, struct graphVertex *vertex){
	if (IsFullStack(s)) {
		printf("Error stack is full");
		return;
	}
	else {
		s->topOfStack++;
		s->vertexArray[s->topOfStack] = vertex;
	}

}

//Pops and returns the top element in the stack and decrements the top of stack by one
struct graphVertex* PopStack(Stack s){
	struct graphVertex* popVertex;
	if (!IsEmptyStack(s)) {
		popVertex = s->vertexArray[s->topOfStack];
		s->topOfStack--;
		return popVertex;

	}
	else {
		printf("Error popstack");
		return;
	}
}

//Returns the top of the stack 
struct graphVertex* TopOfStack(Stack s){
	if (!IsEmptyStack(s))
		return s->vertexArray[s->topOfStack];
	else {
		printf("The stack is empty\n");
		return -1;
	}
}

//Shows the content of the stack. This does not change the content of the stack.
void DisplayStack(Stack s){
	int i;
	printf("Stack content:\n");
	for (i = s->topOfStack; i >= 0; i--)
		printf("\t--> %d\n", s->vertexArray[i]);
}