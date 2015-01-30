#include "linkedList.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
	assertEqual(strcmp(*(String *)((*stringNode).data),"Krati"),0);
	assert((*stringNode).next==0);
	free(stringNode);
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
	Node *doubleNode = create_node(&c);
	add_to_list(&list,doubleNode);
	assert(*(double *)(*(list.head)).data==21.1);
	assert(*(double *)(*(list.tail)).data==21.1);
	free(doubleNode);
}

void test_add_to_list_adds_the_given_char_node_in_the_list() {
	char c = 'A';
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(char *)(*(list.head)).data,'A');
	free(charNode);
}

void test_add_to_list_adds_the_given_string_node_in_the_list() {
	String c = "Krati";
	LinkedList list = createList();
	Node *stringNode = create_node(&c);
	add_to_list(&list,stringNode);
	assertEqual(strcmp(*(String *)(*(list.head)).data,"Krati"),0);
	assertEqual(strcmp(*(String *)(*(list.tail)).data,"Krati"),0);
	free(stringNode);
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
	free(node1);
	free(node2);
}

void test_add_to_list_should_add_two_nodes_into_a_linkedList_with_a_string_type_data() {
	char *c = "Krati",*d = "Jain";
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(strcmp(*(String *)(*(list.head)).data,"Krati"),0);
	assertEqual(strcmp(*(String *)(*(list.tail)).data,"Jain"),0);
	free(node1);
	free(node2);
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
	Node *charNode = create_node(&data);
	int result = add_to_list(&list,charNode);
	assertEqual(*(char*)get_first_element(list),'a');
	free(charNode);
}

void test_get_first_element_returns_first_element_of_the_list_of_string_type (){
	String data = "Dolly";
	LinkedList list = createList();
	Node *stringNode = create_node(&data);
	int result = add_to_list(&list,stringNode);
	assert(*(String*)get_first_element(list)=="Dolly");
	free(stringNode);
}

void test_get_first_element_returns_first_element_of_the_two_elementList_of_string_type (){
	String data1 = "Dolly";
	String data2 = "Krati";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(strcmp(*(String*)get_first_element(list),"Dolly"),0);
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
	Node *floatNode = create_node(&data);
	int result = add_to_list(&list,floatNode);
	assertEqual(*(float*)get_last_element(list),(float)20.7);
	free(floatNode);
}

void test_get_last_element_returns_last_element_of_the_list_of_char_type (){
	char data = 'a';
	LinkedList list = createList();
	Node *charNode = create_node(&data);
	int result = add_to_list(&list,charNode);
	assertEqual(*(char*)get_last_element(list),'a');
	free(charNode);
}

void test_get_last_element_returns_last_element_of_the_two_elementList_of_string_type (){
	String data1 = "Dolly";
	String data2 = "Krati";
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(strcmp(*(String*)get_last_element(list),"Krati"),0);
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

void myCeil(void* data){
	*(float*)data = (float)ceil(*(float*)data);
}

void test_traverse_should_convert_all_list_float_in_their_Ceil_value_with_myCeil_function_in_FLOAT(){
	float data1 = 1.54, data2 = 0.012, data3 = 99.9;
	LinkedList list = createList();
	Node *node1 = create_node(&data1),*node2 = create_node(&data2),*node3 = create_node(&data3);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	traverse(list,myCeil);
	assertEqual(*((float*)node1->data), 2.000000);
	assertEqual(*((float*)node2->data), 1.000000);
	assertEqual(*((float*)node3->data), 100.000000);
	free(node1);
	free(node2);
	free(node3);
}

void myFloor(void* data){
	*(double*)data = (double)floor(*(double*)data);
}

void test_traverse_should_convert_all_list_double_in_their_floor_value_with_myFloor_function_in_DOUBLE(){
	double data1 = 1.54, data2 = 0.012, data3 = 99.9;
	LinkedList list = createList();
	Node *node1 = create_node(&data1),*node2 = create_node(&data2),*node3 = create_node(&data3);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	traverse(list,myFloor);
	assertEqual(*(double*)node1->data, 1.000000);
	assertEqual(*(double*)node2->data, 0.000000);
	assertEqual(*(double*)node3->data, 99.000000);
	free(node1);
	free(node2);
	free(node3);
}

void toUpper(void* data){
	*(char*)data = (char)toupper(*(char*)data);
}

void test_traverse_should_convert_all_list_chars_in_upperCase_with_myToUpper_function_in_CHAR(){
	char data1 = 'a', data2 = 'b', data3 = 'c';
	LinkedList list = createList();
	Node *node1 = create_node(&data1),*node2 = create_node(&data2),*node3 = create_node(&data3);
	add_to_list(&list, node1);
	add_to_list(&list, node2);
	add_to_list(&list, node3);
	traverse(list,toUpper);
	assertEqual(*((char*)node1->data), 'A');
	assertEqual(*((char*)node2->data), 'B');
	assertEqual(*((char*)node3->data), 'C');
	free(node1);
	free(node2);
	free(node3);
}

void stringToUpper(void* data){
	int i, length = strlen(data);
	for(i=0; i < length; i++){
		((char*)data)[i] = (char)toupper(((char*)data)[i]);
	}
}

void test_traverse_should_convert_string_to_upperCase_with_stringToUpper_function_for_STRING(){
	char data[] = "Jungle Jungle baat chali hai";
	char expected[] = "JUNGLE JUNGLE BAAT CHALI HAI";
	LinkedList list = createList();
	Node *new_node = create_node(data);
	list = createList();
	add_to_list(&list, new_node);
	traverse(list,stringToUpper);
	assertEqual(strcmp((char*)new_node->data,expected),0);
	free(new_node);
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
	assertEqual(strcmp(*(String*)getElementAt(list, 2),"Dolly"),0);
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

void test_deleteElementAt_1_deletes_the_second_element (){
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(indexOf(list, &data3),2);
	assertEqual(list.count,3);
	assertEqual(*((int*)deleteElementAt(&list, 1)), data2);
	assertEqual(indexOf(list, &data3),1);
	assertEqual(list.count,2);
	free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_2_when_index_is_0 () {
    int data1 = 2, data2 = 4, data3 = 6;
    LinkedList list = createList();
    Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
    assertEqual(add_to_list(&list, node1), 1);
    assertEqual(add_to_list(&list, node2), 1);
    assertEqual(add_to_list(&list, node3), 1);

    assertEqual(*(int*)deleteElementAt(&list, 0), data1);
    assert(list.head==node2);
    free(node1);
	free(node2);
	free(node3);
}

void test_deleteElementAt_should_return_6_when_index_is_2 () {
    int data1 = 2, data2 = 4, data3 = 6;
    LinkedList list = createList();
    Node_ptr node1 = create_node(&data1), node2 = create_node(&data2), node3 = create_node(&data3);
    assertEqual(add_to_list(&list, node1), 1);
    assertEqual(add_to_list(&list, node2), 1);
    assertEqual(add_to_list(&list, node3), 1);

    assertEqual(*(int*)deleteElementAt(&list, 2), data3);
    assert(list.tail==node2);
    free(node1);
	free(node2);
	free(node3);
}

void test_asArray_populates_array_with_elements_in_list () {
	int *array[3];
	int data1 = 2, data2 = 4, data3 = 6;
	LinkedList list = createList();
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual(asArray(list, (void*)&array),1);
	assertEqual(*(int*)array[0], data1);
	assertEqual(*(int*)array[1], data2);
	assertEqual(*(int*)array[2], data3);
	free(node1);
	free(node2);
	free(node3);
}

int isEven(void *data){
	return *(int*)data % 2 == 0;
}

void test_filter_gives_list_of_even_numbers(){
	int data1 = 18, data2 = 12, data3 = 13, data4 = 15;
	LinkedList list = createList();
	LinkedList *evenNumbers;
	Node *node1 = create_node(&data1), *node2 = create_node(&data2), *node3 = create_node(&data3), *node4 = create_node(&data4);

	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	add_to_list(&list,node4);

	evenNumbers = filter(list, isEven);

	assert(evenNumbers->head->data==&data1);
	assert(evenNumbers->tail->data==&data2);
	assertEqual(evenNumbers->count,2)
	free(node1);
	free(node2);
	free(node3);
	free(node4);
}