#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//Minimum queue size - minimum number of elements that 
//can be stored in a queue
#define MIN_QUEUE_SIZE 5
//Maximum queue size - maximum number of elements that
//can be stored in a queue
#define MAX_QUEUE_SIZE 100


//Queue record that holds the following data:
//capacity: the capacity of the queue, 
//front: index of the front element
//rear: index of the rear element
//size: size of the queue
//array: the array to hold the data in the stack
struct QueueRecord{
	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};

typedef struct QueueRecord *Queue;

//Function signatures
Queue create_queue(int);
void make_empty_queue(Queue);
int succ(Queue, int);
void enqueue(Queue q, int val);
int dequeue(Queue);
int front_of_queue(Queue);
int rear_of_queue(Queue);
int is_empty_queue(Queue);
int is_full_queue(Queue);
void display_queue(Queue);

int main(){
	int queue_size;
	int exit, val;
	char command;

	printf("Enter queue size: ");
	scanf("%d", &queue_size);
	Queue q = create_queue(queue_size);

	exit = 0;

	while (!exit)
	{
		fflush(stdin);
		printf("\nEnter command \ni)nitialize \ne)nqueue \nd)equeue \nf)ront queue \nr)ear queue \nt)erminate: ");
		scanf("%c", &command);
		fflush(stdin);

		switch (command){
		case 'i':
			make_empty_queue(q);
			break;
		case 'e':
			printf("enter value: ");
			scanf("%d", &val);
			enqueue(q, val);
			break;
		case 'd':
			val = dequeue(q);
			break;
		case 'f':
			val = front_of_queue(q);
			if (val != -1)
				printf("front element is %d\n", val);
			break;
		case 'r':
			val = rear_of_queue(q);
			if (val != -1)
				printf("rear element is %d\n", val);
			break;
		case 't':
			exit = 1;
			break;

		default:
			printf("command not recognized\n");
			break;
		}
		display_queue(q);

	}

	printf("\n\n");
	return 0;
}


Queue create_queue(int max_elems){
	if (max_elems < MIN_QUEUE_SIZE)
		printf("You have given smaller elements than min queue size\n");

	Queue q = (Queue)malloc(sizeof(struct QueueRecord));
	if (q == NULL)
		printf("Could not allocate queue\n");
	
	q->array = (int *)malloc(sizeof(int) * max_elems);
	q->capacity = max_elems;
	make_empty_queue(q);
	return q;
}

void make_empty_queue(Queue q){
	q->size = 0;
	q->front = 1;
	q->rear = 1;
}

int is_empty_queue(Queue q) { return(q->size == 0); }

int is_full_queue(Queue q) { return (q->size == q->capacity);  }

/*Moves the given value by one, if it is the end of the array, it makes the index 0*/
int succ(Queue q, int val){
	//TO BE COMPLETED  
	val++;
	if (val == q->capacity) {
		val = 0;
	}
	return val;
}

/*Adds a new value to the rear of the queue*/
void enqueue(Queue q, int val) {

	if (is_full_queue(q)) {
		printf("Queue is full \n");
		return;
	}
	else {
		q->size++;
		q->rear = succ(q, q->rear);
		q->array[q->rear] = val;
		q->rear++;
	}
}

/*Removes a value from the front of the queue*/
int dequeue(Queue q){
	int val;
	if (!is_empty_queue(q)) {
		val = q->array[q->front];
		q->size--;
		q->front = succ(q, q->front);
	}
	else {
		printf("Can't dequeue from an empty queue");
		return -1;
	}
	return val;
}


/*Gives the front element in the queue*/
int front_of_queue(Queue q) { return q->array[q->front]; }

/*Gives the rear element in the queue*/
int rear_of_queue(Queue q){ return q->array[q->rear]; }

/*Displays the content of the queue*/
void display_queue(Queue q){
	int i, pos;

	printf("Front: %d\n", q->front);
	printf("Rear: %d\n", q->rear);
	pos = q->front;
	printf("Queue content:\n");

	for (i = 0; i <q->size; i++){
		printf("\t--> %d\n", q->array[pos]);
		pos = succ(q, pos);
	}
}
