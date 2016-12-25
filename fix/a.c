#include <stdio.h>
#include <string.h>

#define MAX_NUM 13

void init_level(int level[])
{
	int i;
	for(i=0; i<MAX_NUM; ++i){
		level[i]=-1;
	}
}

void print_level(int level[])
{
	int i;
	for(i=0; i<MAX_NUM; ++i){
		printf("%d ", level[i]);
	}
	printf("\n");
}

int input_Number(int num, int *level)
{
	int i;

	if(num < 10 || num > 12){
		return -1;
	}

	init_level(level);

	for(i=1; i<=num; ++i){
		scanf("%d", &level[i]);
	}

	return 0;
}

unsigned int process(int num, int level[])
{
	int i;
	int rval=0;

	for(i=1; i<=num; ++i){
		if(level[i] == i)
			++rval;
	}
	return rval;
}

int main(void)
{
	int C;
	int i;
	int level[MAX_NUM];
	unsigned int num;
	unsigned int rval=0;

	scanf("%d", &C);

	for(i=0; i<C; ++i){
		scanf("%d",&num);
		rval = input_Number(num, level);
//		print_level(level);
		rval = process(num, level);
		printf("%u\n",rval);
	}

	return 0;
}
