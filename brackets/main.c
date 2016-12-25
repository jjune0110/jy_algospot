#include <stdio.h>
#include <string.h>

#define MAX	10001

char stack[MAX];
int top;

void printStack(void)
{
	int i;

	for(i=0; i<top; ++i)
		printf("%c\n", stack[i]);

	printf("\n========\n");
}

int push(char data)
{
	if(top > MAX)
		return -1;

	stack[top] = data;
	++top;

	return 0;
}

char pop(void)
{
	char rch;

	if(top < 0)
		return -1;

	--top;
	rch = stack[top];

	return rch;
}

int check(char open, char close)
{
	int rval = -1;

	if(open == '{' && close == '}'){
		rval = 1;
	}
	else if(open == '[' && close == ']'){
		rval = 1;
	}
	else if(open == '(' && close == ')'){
		rval = 1;
	}
	else {
		rval = -1;
	}

	return rval;
}

int process(void)
{
	char str[MAX];
	char rch;
	int rval=-1;
	int len;
	int i;

	memset(str, 0x00, sizeof(char)*MAX);

	fgets(str, MAX, stdin);

	len = strlen(str)-1;

	for(i=0; i<len; ++i){
		if(str[i] == '{' || str[i] == '(' || str[i] == '['){
			rval = push(str[i]);
			if(rval < 0)
				return -1;
		}
		else{
			rch = pop();

			rval = check(rch, str[i]);
			if(rval < 0)
				return -1;
		}
	}

	if(top > 0)
		return -1;

	return rval;
}

void init(void)
{
	memset(stack, 0x00, sizeof(char)*MAX);
	top = 0;
}

int main(void)
{
	int num;
	int rval;
	int i;

	scanf("%d\n", &num);
	if(num <0 || num > 100)
		return -1;

	for(i=0; i<num; ++i){
		init();
		rval = process();
		if(rval < 0)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}

