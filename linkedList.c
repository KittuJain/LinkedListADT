#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList(void){
	LinkedList *list;
	list = malloc(sizeof(LinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return *list;
}