#include "linkedList.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>

void test_createList_creates_a_linkedList_of_int_type (){
	LinkedList list;
	list = createList();
	assertEqual((int)list.head, 0);
	assertEqual((int)list.tail, 0);
	assertEqual(list.count, 0);
}

void test_createNode_creates_a_node_of_integer_type () {
	int data = 20; 
	Node *intNode = create_node(&data);
	assertEqual((*(int*)(intNode->data)),20);
	assertEqual((int)(intNode->next),0 );
}