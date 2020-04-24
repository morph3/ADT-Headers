#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*A Node declaration to store a value and a link*/
struct Node{
	int val;
	struct Node *next;
};

/*Queue Record that will store the following:
size: total number of elements stored in the list
front: it shows the front node of the queue (front of the queue)
rear: it shows the rare node of the queue (rear of the queue)*/
struct QueueRecord{
	struct Node *front;   /* pointer to front of queue */
	struct Node *rear;    /* pointer to rear of queue */
	int size;             /* number of items in queue */
};
typedef struct QueueRecord *queue;
typedef struct Node *node;

queue create_queue();
void make_empty_queue(queue);
int queue_size(queue);
void enqueue(queue, int);
int dequeue(queue);
int front_of_queue(queue);
int rear_of_queue(queue);
int is_empty_queue(queue);
void display_queue(queue);

int main(){
	int exit, val;
	char command;

	queue q = create_queue();

	exit = 0;

	while (!exit){
		printf("\nEnter command \ni)nitialize \ne)nqueue \nd)equeue \nf)ront queue \nr)ear queue \nt)erminate: ");
		fflush(stdin);
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
				printf("Dequeued value is : %d\n", dequeue(q));
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

	printf("\n");
	return 0;
}

/*This function initialises the queue*/
queue create_queue(){
	queue q = (queue)malloc(sizeof(struct QueueRecord));
	if (q == NULL) {
		printf("Could not allocate it \n");
	}
	make_empty_queue(q);
	return q;
}



/*This function sets the queue size to 0, and creates a dummy element
and sets the front and rear point to this dummy element*/
void make_empty_queue(queue q){
	node temp = (node)malloc(sizeof(struct Node));
	temp->next = NULL;
	q->front = temp;
	q->rear = q->front;
	q->size = 0;
}

int is_empty_queue(queue q) { return (q->size == 0); }
int queue_size(queue q) { return q->size;  }

/*Enqueue - Adds a new element to the queue, simly creates a node and
adds it to the rear of the queue*/
void enqueue(queue q, int val){
	node temp = (node)malloc(sizeof(struct Node));
	temp->val = val;
	temp->next = NULL;

	
	q->rear->next = temp;
	q->rear = temp;
	q->size++;

}

/*Dequeue - Removes a node from the queue, basically removes a node from
the front of the queue*/
int dequeue(queue q){
	int val = q->front->next->val;
	q->front = q->front->next;
	q->size--;
	return val;
}

/*Returns the value stored in the front of the queue*/
int front_of_queue(queue q){
	if (!is_empty_queue(q))
		return q->front->next->val;
	else{
		printf("The queue is empty\n");
		return -1;
	}
}

/*Returns the value stored in the rear of the queue*/
int rear_of_queue(queue q){
	if (!is_empty_queue(q))
		return q->rear->val;
	else{
		printf("The queue is empty\n");
		return -1;
	}
}

/*Displays the content of the queue*/
void display_queue(queue q){
	if (is_empty_queue(q)) {
		printf("Queue is empty \n");
		return;
	}
	else {
		node traverser = q->front->next;
		while (traverser->next != NULL) {
			printf("--> %d  ", traverser->val);
			traverser = traverser->next;
		}
		printf("--> %d  ", traverser->val);
		printf("\n");

	}
}
