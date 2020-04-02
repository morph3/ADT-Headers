#include "linked_list.h"

void insert_val(list l, int pos, int val){
    if (DEBUG){
            printf("Insertion started\n");

    }
    node tmpnode = (struct node *)malloc(sizeof(struct node));
    tmpnode->next = NULL;
    tmpnode->val = val;


    //if its in the last place 
    if (pos > l->size){
        l->tail->next = tmpnode;
        l->tail = tmpnode;
        l->size++;
        return;
    }


    node traverser = l->head;
    while(pos != 0){
        traverser = traverser->next;
        if (DEBUG){
            printf("Traverser next points to : 0x%x\n", traverser->next);

        }
        pos--;
    }

    tmpnode->next = traverser->next;
    traverser->next = tmpnode;
    if(DEBUG){
        printf("Traverser next points to : 0x%x\n", traverser->next);
        printf("Temporary node points to : 0x%x\n\n", traverser->next);
        printf("Insertion completed\n");

    }
    l->size++;

}

void print_list(struct ListRecord *l){
    struct node *tmp_node = l->head->next;
    while(tmp_node->next != NULL){
        printf("%d ",tmp_node->val);
        tmp_node = tmp_node->next;
    }
    printf("%d ",tmp_node->val);
    printf("\n");
}

list create_list(void){
    list l;
    l = (struct ListRecord *) malloc(sizeof(struct ListRecord));
    if (l == NULL) {
        printf("Could not allocated !\n");
    }
    make_empty_list(l);
    return l;
}

void make_empty_list(list l) {
    l->head = (struct node *) malloc(sizeof(struct node));
    if (l->head == NULL)
        printf("Could not allocated !\n");

    l->head->next = NULL;
    l->tail = l->head;
    l->size = 0;
}

int is_empty_list(list l){
	return l->size == 0;
}

int head_of_list(list l){
	if (!is_empty_list(l)){
		return l->head->next->val;        
    }
	else{
		printf("The linked list is empty\n");
		return -1;
	}
}

int tail_of_list(list l){
	if (!is_empty_list(l)){
		return l->tail->val;
    }
	else{
		printf("The linked list is empty\n");
		return -1;
	}
}

list sorted_merge(list l1, list l2){

	sort(l1);
	sort(l2);
	DisplayList(l1);
	DisplayList(l2);
	
	node traverser1 = l1->head->next;
	node traverser2 = l2->head->next;
	
	list merged_list = CreateList();

	int size = (l1->size > l2->size) ? l1->size : l2->size;
	int i;

	for(i=0; i< size; i++){
			//insert_val(merged_list,i,traverser1->val);
			//insert_val(merged_list,i,traverser2->val);
			InsertTail(merged_list,traverser1->val);
			InsertTail(merged_list,traverser2->val);
				
			traverser1 = traverser1->next;
			traverser2 = traverser2->next;
		
	}
	//sort(merged_list);

	return merged_list;
}

void remove_duplicate(list l){
    // this should get called in a while loop to make sure there is no duplicate
	sort(l);
	node tmpnode = l->head->next;
	while(1){
		if(tmpnode->val == tmpnode->next->val){
			break;
		}
		tmpnode = tmpnode->next;
	}
	delete_node(l,tmpnode->val);
	l->size--;
}

int get_element_at(list l, int pos){
	node tmpnode;
	tmpnode = l->head->next;

	while(pos != NULL){
		tmpnode = tmpnode->next;
		pos--;
	}
	return tmpnode->val;

}

int get_position(list l, int val){
	int pos;
	node tmpnode;
	tmpnode = l->head->next;
	while(1){
		if(tmpnode->val == val){
			break;
		}
		tmpnode = tmpnode->next;
	}
	return pos;
}

void delete_node(list l, int val){
	node tmpnode = l->head->next;
	while(1){
		if(tmpnode->next->val == val){
			break;
		}
		tmpnode = tmpnode->next;
	}

	//   | tmpnode->next |  val | another node |
	//  	          |______|
	//	
	tmpnode->next = tmpnode->next->next;
	tmpnode = tmpnode->next;
	free(tmpnode);
	l->size--;
}

void insert_head(list l , int val){
    node tmpnode = (node)malloc(sizeof(struct node));
	tmpnode->val = val;
    tmpnode->next = NULL;
    
    if(l->size == 0 ){
            l->head = l->tail = tmpnode;
            l->size++;
    }
    else{
        tmpnode->next = l->head;
        l->head = tmpnode;
        l->size++;
    }
}

void insert_tail(list l , int val){
    node traverser,tmpnode;

    tmpnode = (node)malloc(sizeof(struct node));

    tmpnode->val = val;
    tmpnode->next = NULL;

    traverser = l->head;
    if(l->size==0){
        l->head = l->tail = tmpnode;
        l->size++;
    }
    else{
        while(traverser->next != NULL){
            traverser = traverser->next;
        }
        traverser->next = tmpnode;
        l->tail = tmpnode;
        l->size++;
    }
}

void sort(list l) {
    node traverser;
    traverser = l->head;
	int condition;
    while (traverser != NULL) {
        node traverser_next;
        if (traverser == NULL) {
            return;
        }
        traverser_next = traverser->next;
        while (traverser_next != NULL) {
        	
        	// there goes the condition that you want to sort 
			condition = traverser->val > traverser_next->val;
            if (condition) {
                data_swap(traverser, traverser_next);
            }
            traverser_next = traverser_next->next;
        }
        traverser = traverser->next;
        free(traverser_next);
    }
    free(traverser);
}


void data_swap(node a, node b) {
    int temp;
    temp = a->val;
    a->val = b->val;
    b->val = temp;

}
