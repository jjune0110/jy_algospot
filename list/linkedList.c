#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct list_node *list_pointer;
typedef struct list_node{
	int data;
	list_pointer link;
}list_node;
list_pointer ptr	= NULL;
list_pointer rear	= NULL;


int init_node(void)
{
	ptr		= (list_pointer)malloc(sizeof(list_node));
	rear	= (list_pointer)malloc(sizeof(list_node));

	ptr->data = 0;
	ptr->link = NULL;

	rear = ptr;

	return 0;
}

int add_node(int pData)
{
	list_pointer temp;

	temp = (list_pointer)malloc(sizeof(list_node));

	printf("[%s:%d] Start\n", __FUNCTION__, __LINE__);

	temp->data = pData;
	temp->link = NULL;

	if(ptr==rear)
		ptr->link = temp;

	rear->link = temp;
	rear = temp;

	printf("[%s:%d] Finish\n", __FUNCTION__, __LINE__);

	return 0;
}

int print_node(void)
{
	int i;
	list_pointer node;

	node = (list_pointer)malloc(sizeof(list_node));

	printf("[%s:%d] Start\n", __FUNCTION__, __LINE__);
	node = ptr->link;

	for(i=1; node!=NULL; ++i){
		printf("[%d:%d] ", i, node->data);
		node = node->link;
	}
	printf("[%s:%d] Finish\n", __FUNCTION__, __LINE__);

	return 0;
}

int find_node(pData)
{
	int i;
	int rval;
	list_pointer node;

	node = (list_pointer)malloc(sizeof(list_node));

	printf("[%s:%d] Start\n", __FUNCTION__, __LINE__);
	node = ptr->link;

	for(i=1; node!=NULL; ++i){
		if(node->data == pData)
			break;
		node = node->link;
	}
	if(node!=NULL)
		rval = i;
	else
		rval = -1;
	printf("[%s:%d] Finish index:%d\n", __FUNCTION__, __LINE__, rval);

	return i;
}

void main(void)
{
	int num;
	int rval;

	printf("[%s:%d] Start\n", __FUNCTION__, __LINE__);

	init_node();

	while(1){
		scanf("%d", &num);
		if(num < 0) break;
		add_node(num);
	}

	printf("find one node");
	scanf("%d", &num);
	rval = find_node(num);
	printf("[%s:%d] index:%d\n", __FUNCTION__, __LINE__, rval);

	print_node();

	printf("[%s:%d] Finish\n", __FUNCTION__, __LINE__);
}
