#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>


struct ListNode{
   	int val;
    struct ListNode *next;
};

struct ListRecord{
    struct ListNode *head;
    struct ListNode *tail;
    int size;
};

typedef struct ListNode *node;
typedef struct ListRecord *List;


List CreateList(void);
void MakeEmptyList(List list);
int ListSize(List list);
node ListHead(List list);
node ListTail(List list);
void DisplayList(List list);
void InsertHead(List list , int val);
void InsertTail(List list , int val);
int IsEmpty(List list);
void sort(List list);
void dataSwap(struct ListNode *a, struct ListNode *b);
#endif
