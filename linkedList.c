#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node_ptr create_node(void *data){
	Node_ptr node;
	node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int add_to_list(LinkedList* list,Node_ptr node){
	if(list->head == NULL){
		list->head = node;
	}
	else{
		list->tail->next = node;
	}
	list->tail = node;		
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*function_ptr)(void *data)){
	void* walker = list.head;
	while(walker != NULL){
		function_ptr(list.head->data);
		walker = list.head->next;
	}
}

void* getElementAt(LinkedList list, int index){
	int count = 0;
	Node_ptr walker = list.head;
	while(walker != NULL){
		if(count==index)
			return walker->data;
		count++;
		walker = list.head->next;
	}
	return NULL;
}