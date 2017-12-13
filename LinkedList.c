#include "LinkedList.h"


List CreateList(void){
    List list;
    list = (struct ListRecord *) malloc(sizeof(struct ListRecord));
    if (list == NULL) {
        printf("Could not allocated !\n");
    }
    MakeEmptyList(list);
    return list;
}

void MakeEmptyList(List list) {
    list->head = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (list->head == NULL)
        printf("Could not allocated !\n");

    list->head->next = NULL;
    list->tail = list->head;

    list->size = 0;
}

int ListSize(List list){
    return(list->size);
}

node ListHead(List list){
    // returns a node
	return(list->head);
}

node ListTail(List list){
	// returns a node
    return(list->tail);
}

void DisplayList(List list){
        node t;
        printf("\nList content is below \n");
        t = list->head;
        while(t != NULL){
            printf("%d", t->val);
            printf("\n");
            t = t->next;
        }
        free(t);
        printf("\n");

}

void InsertHead(List list , int val){
    node newNode;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // dummy node
	newNode->val = val;
    newNode->next = NULL;
    
    if(list->size == 0 ){
            list->head = list->tail = newNode;
            list->size++;
    }
    else{
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
}
void InsertTail(List list , int val){
    node current,newNode;
    // node newNode = (node)malloc(sizeof(struct ListNode));
    
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = val;
    newNode->next = NULL;

    current = list->head;
    if(list->size==0){
        list->head = list->tail = newNode;
        list->size++;
    }
    else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        list->tail = newNode;
        list->size++;
    }
}

int IsEmpty(List list){
    return (list->size == 0);
}

void sort(List list) {
    node currNode;
    currNode = list->head;
    while (currNode != NULL) {
        node nextNode;
        if (currNode == NULL) {
            return;
        }
        nextNode = currNode->next;
        while (nextNode != NULL) {
        	
        	// there goes the condition that you want to sort 
			condition = currNode->val > nextNode->val;
            if (condition) {
                dataSwap(currNode, nextNode);
            }
            nextNode = nextNode->next;
        }
        currNode = currNode->next;
    }
    free(currNode);
}

void dataSwap(struct ListNode *a, struct ListNode *b) {

    //  swapping all the information
    int temp;
    temp = a->val;
    a->val = b->val;
    b->val = temp;

}
