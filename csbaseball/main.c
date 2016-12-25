#include <stdio.h>

int process(void)
{
	int csScore, hpScore;
	int first = 0;
	int second = 0;
	int third = 0;
	int hit =0;

	scanf("%d %d\n", &csScore, &hpScore);
	if(csScore > hpScore) return 0;
	else return hpScore - csScore + 4;

	/*
	while(1){
		if(third){
			third = 0;
			++csScore;
		}

		if(second){
			second = 0;
			third = 1;
		}

		if(first){
			first = 0;
			second = 1;
		}

		++hit;
		first = 1;

		if(csScore > hpScore)
			break;
	}
	*/


	return hit;
}

int main(void)
{
	int num;
	int rval;
	int i;

	scanf("%d\n", &num);

	for(i=0; i<num; ++i){
		rval = process();
		printf("%d\n", rval);
	}

	return 0;

}
