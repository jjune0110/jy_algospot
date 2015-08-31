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
	list_pointer node1, node2, temp;

	node1 = (list_pointer)malloc(sizeof(list_node));
	node2 = (list_pointer)malloc(sizeof(list_node));
	temp = (list_pointer)malloc(sizeof(list_node));

	temp->data = pData;
	temp->link = NULL;


	/* first node */
	if(ptr->link==NULL){
		ptr->link = temp;
		return 0;
	}

	node2=ptr;
	for(node1=ptr->link; node1; node1=node1->link){
		/* insert */
		if(pData < node1->data){
			temp->link = node1;
			node2->link = temp;
			break;
		}

		node2 = node1;
	}

	/* last node */
	if(node1==NULL){
		node2->link = temp;
	}

	return 0;
}

int print_node(void)
{
	int i;
	list_pointer node;

	node = (list_pointer)malloc(sizeof(list_node));

	node = ptr->link;

	printf("%s\n", __FUNCTION__);
	for(i=1; node!=NULL; ++i){
		printf("[%d:%d] ", i, node->data);
		node = node->link;
	}
	printf("\n");

	return 0;
}

void main(void)
{
	int num;
	int rval;

	init_node();

	while(1){
		scanf("%d", &num);
		if(num < 0) break;
		add_node(num);
	}

	print_node();
}
