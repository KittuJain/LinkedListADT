#include "linkedList.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>

void test_createList_creates_a_linkedList_of_int_type (){
	LinkedList list;
	list = createList();
	assert(list.head==0);
	assert(list.tail==0);
	assertEqual(list.count, 0);
}

void test_createNode_creates_a_node_of_integer_type () {
	int data = 20; 
	Node *intNode = create_node(&data);
	assertEqual((*(int*)(intNode->data)),20);
	assert((intNode->next)==0 );
	free(intNode);
}

void test_createNode_creates_a_node_of_float_type () {
	float data = 20.7; 
	Node *floatNode = create_node(&data);
	assertEqual((*(float*)(floatNode->data)),(float)20.7);
	assert((floatNode->next)==0 );
	free(floatNode);
}

void test_createNode_creates_a_node_of_char_type () {
	char data = 'k'; 
	Node *charNode = create_node(&data);
	assertEqual((*(char*)(charNode->data)),'k');
	assert(charNode->next==0 );
	free(charNode);
}

void test_createNode_creates_a_node_of_string_type() {
	String c = "Krati";
	Node *stringNode = create_node(&c);
	assert(*(String *)((*stringNode).data)=="Krati");
	assert((*stringNode).next==0);
}

void test_add_to_list_adds_the_given_node_in_the_list (){
	LinkedList list = createList();
	Node intNode;
	int result = add_to_list(&list,&intNode);
	assert(list.head==&intNode);
	assert(list.tail==&intNode);
	assertEqual(list.count, 1);
}

void test_add_to_list_adds_the_given_double_node_in_the_list() {
	double c = 21.1;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(double *)(*(list.head)).data==21.1);
	assert(*(double *)(*(list.tail)).data==21.1);
}

void test_add_to_list_adds_the_given_char_node_in_the_list() {
	char c = 'A';
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(char *)(*(list.head)).data,'A');
}

void test_add_to_list_adds_the_given_string_node_in_the_list() {
	String c = "Krati";
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assert(*(String *)(*(list.head)).data=="Krati");
	assert(*(String *)(*(list.tail)).data=="Krati");
}

void test_add_to_list_should_add_two_nodes_into_a_linkedList_with_a_int_type_data () {
	int data1 = 2, data2 = 4;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2);

	assertEqual(add_to_list(&list, node1), 1);
	assertEqual(add_to_list(&list, node2), 1);
	assert(list.head==node1);
	assert(list.tail==node2);
	assert(node1->next==node2);
	free(node1);
	free(node2);
}

void test_add_to_list_should_add_two_nodes_into_a_linkedList_with_a_char_type_data() {
	char c = 'A',d = 'B';
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(char *)(*(list.head)).data,'A');
	assertEqual(*(char *)(*(list.tail)).data,'B');
}

void test_add_to_list_should_add_two_nodes_into_a_linkedList_with_a_string_type_data() {
	char *c = "Krati",*d = "Jain";
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(String *)(*(list.head)).data=="Krati");
	assert(*(String *)(*(list.tail)).data=="Jain");
}

void test_get_first_element_returns_first_element_of_the_list (){
	int data = 20;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int	result = add_to_list(&list,intNode);
	assertEqual(*(int*)get_first_element(list),20);
	free(intNode);
}

void test_get_first_element_returns_first_element_of_the_list_of_float_type (){
	float data = 20.7;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assertEqual(*(float*)get_first_element(list),(float)20.7);
	free(intNode);
}

void test_get_first_element_returns_first_element_of_the_list_of_char_type (){
	char data = 'a';
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assertEqual(*(char*)get_first_element(list),'a');
	free(intNode);
}

void test_get_first_element_returns_first_element_of_the_list_of_string_type (){
	String data = "Dolly";
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assert(*(String*)get_first_element(list)=="Dolly");
	free(intNode);
}

void test_get_first_element_returns_first_element_of_the_two_elementList_of_string_type (){
	String data1 = "Dolly";
	String data2 = "Krati";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(String*)get_first_element(list)=="Dolly");
	free(node1);
	free(node2);
}

void test_get_last_element_returns_last_element_of_the_list (){
	int data = 20;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assertEqual(*(int*)get_last_element(list),20);
	free(intNode);
}

void test_get_last_element_returns_last_element_of_the_list_of_float_type (){
	float data = 20.7;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assertEqual(*(float*)get_last_element(list),(float)20.7);
	free(intNode);
}

void test_get_last_element_returns_last_element_of_the_list_of_char_type (){
	char data = 'a';
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list,intNode);
	assertEqual(*(char*)get_last_element(list),'a');
	free(intNode);
}

void test_get_last_element_returns_last_element_of_the_two_elementList_of_string_type (){
	String data1 = "Dolly";
	String data2 = "Krati";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assert(*(String*)get_last_element(list)=="Krati");
	free(node1);
	free(node2);
}


void add (void* data){
	*(int*)data += 1;
}

void test_traverse_goes_through_a_list_and_increments_each_element_of_list_by_1 (){
	int data = 20;
	LinkedList list = createList();
	Node *intNode = create_node(&data); 
	int result = add_to_list(&list,intNode);
	traverse(list, add);
	assertEqual((*(int*)(intNode->data)),21);
	assert(intNode->next==0 );
	free(intNode);
}

void test_getElementAt_returns_the_first_element_of_list (){
	int data = 10;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	int result = add_to_list(&list, intNode);
	assertEqual(*(int*)getElementAt(list, 0),10);
	free(intNode);
}

void test_getElementAt_returns_the_second_element_of_list (){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(int*)getElementAt(list, 1),4);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_float (){
	float data1 = 2.5, data2 = 4.1, data3 = 6.3;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(float*)getElementAt(list, 1),(float)4.1);
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_char (){
	char data1 = 'k', data2 = 'r', data3 = 'v';
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(*(char*)getElementAt(list, 1),'r');
	free(node1);
	free(node2);
	free(node3);
}

void test_getElementAt_returns_the_second_element_of_list_of_string (){
	char *data1 = "Krati", *data2 = "Ambuj", *data3 = "Dolly";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assert(*(String*)getElementAt(list, 2)=="Dolly");
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_0_when_element_is_present_at_first_position_in_int_data_type(){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data1),0);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_float_data_type(){
	float data1 = 10.23, data2 = 44.24, data3 = 86.78;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_char_data_type(){
	char data1 = 'k', data2 = 'a', data3 = 'v';
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_1_when_element_is_present_at_first_position_in_string_data_type(){
	char *data1 = "Krati", *data2 = "Ambuj", *data3 = "Jain";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data2),1);
	free(node1);
	free(node2);
	free(node3);
}

void test_indexOf_gives_minus_1_when_element_is_not_present_in_int_data_type(){
	int data1 = 2, data2 = 4, data3 = 6, data4 = 20;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data4),-1);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_deletes_the_second_element (){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data3),2);
	deleteElementAt(list, 1);
	assertEqual(indexOf(list, &data3),1);
	free(node1);
	free(node2);
	free(node3);
}