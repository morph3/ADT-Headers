#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1

struct Node {
	int val;
	struct Node *next;
};

struct ListRecord {
	struct Node *head;
	struct Node *tail;
	int size;
};

typedef struct Node *node;
typedef struct ListRecord *list;

void insert_val(list l, int, int);
void insert_head(list l, int val);
void insert_tail(list l, int val);
void reverse_list(list l);
void print_list(list l);
void make_empty_list(list l);
void remove_duplicate(list l);
void delete_node(list l, int val);
void data_swap(node a, node b);
void sort(list l);
void destroy_list(list l);


int is_empty_list(list l);
int head_of_list(list l);
int tail_of_list(list l);
int get_element_at(list l, int pos);
int get_position(list l, int val);

list sorted_merge(list l1, list l2);
list create_list(void);

#endif
