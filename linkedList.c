#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node* create_node(void *data){
	Node* node;
	node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int add_to_list(LinkedList* list,Node* node){
	if(list->head == NULL){
		list->head = node;
		list->tail = node;		
	}
	else{
		list->tail->next = node;
	}
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}