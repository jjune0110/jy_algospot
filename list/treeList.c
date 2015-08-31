#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct list_node *list_pointer;
typedef struct list_node{
	int data;
	list_pointer lLink;
	list_pointer rLink;
}list_node;
list_pointer root	= NULL;


int init_node(void)
{
	root = (list_pointer)malloc(sizeof(list_node));
	root = NULL;

	return 0;
}

list_pointer find_node(list_pointer node, int pData)
{
	int cnt = 0;

	while(node){
		printf("[%s:%d] %d\n", __FUNCTION__, __LINE__, cnt);

		if(pData == node->data) return NULL;
		if(pData < node->data){
			if(node->lLink) node = node->lLink;
			else return node;
		}
		else{
			if(node->rLink) node = node->rLink;
			else return node;
		}
	}

	return NULL;
}

int add_node(list_pointer node, int pData)
{
	list_pointer temp;
	list_pointer ptr;

	printf("[%s:%d] Start\n", __FUNCTION__, __LINE__);
	temp = find_node(node, pData);

	if(temp || !(node)){
		printf("[%s:%d]\n", __FUNCTION__, __LINE__);

		ptr = (list_pointer)malloc(sizeof(list_node));
		ptr->data = pData;
		ptr->lLink = NULL;
		ptr->rLink = NULL;

		if(node){
			printf("[%s:%d]\n", __FUNCTION__, __LINE__);
			if(pData < temp->data) temp->lLink = ptr;
			else temp->rLink = ptr;
		}
		else{
			printf("[%s:%d]\n", __FUNCTION__, __LINE__);
			if(root)
				node = ptr;
			else
				root = ptr;
		}
		printf("[%s:%d]\n", __FUNCTION__, __LINE__);
	}

	printf("[%s:%d] Finish\n", __FUNCTION__, __LINE__);

	return 0;
}

int print_node(list_pointer node)
{
	if(node){
		print_node(node->lLink);
		printf("%d ", node->data);
		print_node(node->rLink);
	}

	return 0;
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
		add_node(root, num);
	}

	print_node(root);

	printf("[%s:%d] Finish\n", __FUNCTION__, __LINE__);
}
