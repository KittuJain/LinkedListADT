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
	list->head = node;
	list->tail = node;
	list->count++;
	return 1;
}
