#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    int priority;
    struct Node *next;
};

struct QueueRecord{
    struct Node *front;   /* pointer to front of queue */
    struct Node *rear;    /* pointer to rear of queue */
    int size;             /* number of items in queue */
};
typedef struct QueueRecord *Queue;
typedef struct Node* QueueNode;
Queue CreateQueue();
void MakeEmptyQueue(Queue);
int QueueSize(Queue);
void Enqueue(Queue q ,int val);
void PriorityEnqueue(Queue q , int val,int priority);
QueueNode Dequeue(Queue q);
QueueNode FrontOfQueue(Queue);
QueueNode RearOfQueue(Queue);
int IsEmptyQueue(Queue q);
void DisplayQueue(Queue);

#endif