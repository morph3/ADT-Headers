#include "Queue.h"

/*This function initialises the queue*/
Queue CreateQueue(){
    Queue myQ;
    myQ = (struct QueueRecord*)malloc(sizeof(struct QueueRecord));
    if(myQ == NULL){
        printf("Could not allocated !\n");
    }
    MakeEmptyQueue(myQ);
    return myQ;
}

/*This function sets the queue size to 0, and creates a dummy element
and sets the front and rear point to this dummy element*/
void MakeEmptyQueue(Queue q){
    q->size = 0;
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    // QueueNode newNode = (QueueNode)malloc(sizeof(struct Node));

    q->front = newNode;
    if(q->front == NULL){
        printf("Could not allocated !");
    }
    q->front->next = NULL;
    q->rear = q->front;
    q->size = 0 ;
}

/*Shows if the queue is empty*/
int IsEmptyQueue(Queue q){
    return((q->size == 0));
}

/*Returns the queue size*/
int QueueSize(Queue q){
    return(q->size);
}

/*Enqueue - Adds a new element to the queue, simply creates a node and
adds it to the rear of the queue*/
void Enqueue(Queue q , int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->priority = 0;
    newNode->val = val;
    newNode->next = NULL;

    q->rear->next = newNode;
    q->rear = newNode;
    q->size++;

}
void PriorityEnqueue(Queue q , int val , int priority){
    struct Node* currNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode =  (struct Node*)malloc(sizeof(struct Node));

    // dummy node
    newNode->val = val;
	newNode->priority = priority;

    currNode = q->front;
    int condition =  currNode->priority <= newNode->priority ;
    if(q->front == NULL || condition){
        newNode->next = q->front;
        q->front = newNode;
        q->size++;
    }
    else{
        while(currNode->next!=NULL && (currNode->next->priority >= newNode->priority) ){
            currNode = currNode->next;
        }
        newNode->next = currNode->next ;
        currNode->next = newNode;
        q->size++;
    }
}

/*Dequeue - Removes a node from the queue, basically removes a node from
the front of the queue*/
QueueNode Dequeue(Queue q){
    struct Node*  temp;
    temp = q->front->next;
    q->front= q->front->next;
    return (temp);
}

/*Returns the value stored in the front of the queue*/
QueueNode FrontOfQueue(Queue q) {
    if (!IsEmptyQueue(q))
        return (q->front->next);
    else
    {
        printf("The queue is empty\n");
        return NULL;
    }
}

/*Returns the value stored in the rear of the queue*/
QueueNode RearOfQueue(Queue q) {
    if (!IsEmptyQueue(q))
        return (q->rear);
    else {
        printf("The queue is empty\n");
        return NULL;
    }
}

/*Displays the content of the queue*/
void DisplayQueue(Queue q){
    struct Node *t;
    if(!IsEmptyQueue(q)){
        t = q->front->next;
        printf("\nQueue content is below\n");
        printf("Val , Priority\n");
        while (t != NULL){
            printf("%d ",t->val);
            printf("%d ", t->priority);
            t = t->next;
            printf("\n");
        }
        free(t);
        printf("\n");
    }
    else{
        printf("Queue is empty \n");
    }
}