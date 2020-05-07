#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>


// Payment type macros 
#define CASH 0 
#define CREDIT_CARD 1

// Age macros 
#define ELDERLY 'E'
#define ADULT 'A'
#define YOUNG 'Y'


struct Node {
	char customerType; // Elderley - Adult - Young
	int customerAge; // age 
	int arrivalTime; // in minutes,  this will represent when they requested to be served by the cashier
	int serviceTime; // in minutes, how long it will take the cashier to serve the customer
	int serviceStartTime; // in minutes, – this will represent the actual time the cashier will start to serve this particular customer
	int cashierId; // first cashier is 1, ... 
	int paymentType; // cash or credit_card , declared macros for them

	int priority; // 

	
	struct Node *next;
};


struct QueueRecord {
	struct Node *front;   /* pointer to front of queue */
	struct Node *rear;    /* pointer to rear of queue */
	int size;             /* number of items in queue */
};
typedef struct QueueRecord *queue;
typedef struct Node *node;


queue create_queue();
void make_empty_queue(queue);
void enqueue(queue q, node customer );
void priority_enqueue(queue q, node customer);
node dequeue(queue q);
node front_of_queue(queue);
node rear_of_queue(queue);
int is_empty_queue(queue q);
void display_queue(queue);


#endif
