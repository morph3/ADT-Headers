#include "Queue.h"

/*This function initialises the queue*/
queue create_queue() {
	queue q = (queue)malloc(sizeof(struct QueueRecord));
	if (q == NULL) {
		printf("Could not allocated !\n");
	}
	make_empty_queue(q);
	return q;
}

/*This function sets the queue size to 0, and creates a dummy element
and sets the front and rear point to this dummy element*/
void make_empty_queue(queue q) {
	node temp = (node)malloc(sizeof(struct Node));
	temp->next = NULL;
	q->front = temp;
	q->rear = q->front;
	q->size = 0;
}

/*Shows if the queue is empty*/
int is_empty_queue(queue q) { return((q->size == 0)); }


/*Enqueue - Adds a new element to the queue, simly creates a node and
adds it to the rear of the queue*/
void enqueue(queue q, node customer) {
	q->rear->next = customer;
	q->rear = customer;
	q->size++;

}
void priority_enqueue( queue q, node customer ) {
	
	node traverser =  q->front;
	int condition = traverser->priority <= customer->priority;
	if (q->front == NULL || condition) {
		customer->next = q->front;
		q->front = customer;
		q->size++;
	}
	else {
		while (traverser->next != NULL && (traverser->next->priority >= customer->priority)) {
			traverser = traverser->next;
		}
		customer->next = traverser->next;
		traverser->next = customer;
		q->size++;
	}
}

/*Dequeue - Removes a node from the queue, basically removes a node from
the front of the queue*/
node dequeue(queue q) {
	if (q->size == 0) {
		// can't dequeue from an empty queue
		return NULL;
	}
	
	node temp = q->front->next;
	q->front = q->front->next;
	q->size--;
	
	return (temp);
}

/*Returns the front node of the queue*/
node front_of_queue(queue q) { return q->front->next ? !(is_empty_queue(q)) : -1; }

/*Returns the rear node of the queue*/
node rear_of_queue(queue q) { return q->rear ? !(is_empty_queue(q)) : -1; }

/*Displays the content of the queue*/
void display_queue(queue q) {
	node traverser;
	if (!is_empty_queue(q)) {
		node traverser = q->front->next;
		printf("\Queue content is below \n");
		printf("Customer Type - Customer Age - ArrivalTime - ServiceTime - Service Start Time - Payment Type - Cashier ID\n");
		while (traverser != NULL) {
			printf("        %c     ", traverser->customerType);
			printf("      %d     ", traverser->customerAge);
			printf("      %d     ", traverser->arrivalTime);
			printf("      %d     ", traverser->serviceTime);
			printf("               %d     ", traverser->serviceStartTime);
			(traverser->paymentType == CASH) ? printf("        Cash     ") : printf("        Credit Card     ");
			printf("     %d     ", traverser->cashierId);
			printf("\n");
			traverser = traverser->next;
	
		}
	}
	else {
		printf("Queue is empty \n");
	}
}
