#include <stdio.h>

int process(void)
{
	int max, w[9], now;
	int i;

	scanf("%d", &max);
	for(i=0; i<9; ++i){
		scanf("%d", &w[i]);
	}

	now = 0;
	for(i=0; i<9; ++i){
		now += w[i];
	}

	if(now <= max)
		return 1;	

	return 0;
}

int main(void)
{
	int i, num;
	int rval;

	scanf("%d", &num);

	for(i=0; i<num; ++i){
		rval = process();
		if(rval)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
