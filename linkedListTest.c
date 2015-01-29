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
	free(intNode);
}

void test_createNode_creates_a_node_of_float_type () {
	float data = 20.7; 
	Node *floatNode = create_node(&data);
	assertEqual((*(float*)(floatNode->data)),(float)20.7);
	assertEqual((int)(floatNode->next),0 );
	free(floatNode);
}

void test_createNode_creates_a_node_of_char_type () {
	char data = 'k'; 
	Node *charNode = create_node(&data);
	assertEqual((*(char*)(charNode->data)),'k');
	assertEqual((int)(charNode->next),0 );
	free(charNode);
}

void test_add_to_list_adds_the_given_node_in_the_list (){
	LinkedList list;
	Node intNode;
	int result;
	list = createList();
	result = add_to_list(&list,&intNode);
	assertEqual(list.head, &intNode);
	assertEqual(list.tail, &intNode);
	assertEqual(list.count, 1);
}


void test_get_first_element_returns_first_element_of_the_list (){
	LinkedList list;
	int result;
	int data = 20;
	Node *intNode; 
	list = createList();
	intNode = create_node(&data);
	result = add_to_list(&list,intNode);
	assertEqual(*(int*)get_first_element(list),20);
}