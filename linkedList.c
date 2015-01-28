#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node * create_node(void *data){
	Node *node;
	node = malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	return node;
}