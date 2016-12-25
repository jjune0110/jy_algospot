#include <stdio.h>

int process(void)
{
	int rX, rY;

	int x[3];
	int y[3];
	int i;

	for(i=0; i<3; ++i){
		scanf("%d %d", &x[i], &y[i]);
	}

	rX = x[0];
	rY = y[0];

	if(rX == x[1])
		rX = x[2];
	else if(rX == x[2])
		rX = x[1];

	if(rY == y[1])
		rY = y[2];
	else if(rY == y[2])
		rY = y[1];


	printf("%d %d\n", rX, rY);


	return 0;
}

int main(void)
{
	int C;
	int i;

	scanf("%d", &C);

	for(i=0; i<C; ++i){
		process();
	}

	return 0;
}
