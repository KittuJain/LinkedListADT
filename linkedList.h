typedef struct linked_list LinkedList;
typedef struct node Node;
typedef struct node* node_ptr;
typedef struct student Student;

struct linked_list{
	node_ptr head;
	node_ptr tail;
	int count;
};

struct node{
	void* data;
	node_ptr next;
};
// int n = 90;

struct student{
	int id;
	int marks;
};

LinkedList createList(void);