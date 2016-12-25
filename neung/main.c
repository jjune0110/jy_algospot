#include <stdio.h>
#include <string.h>

int cvtNum(char* str)
{
	if(!strcmp(str, "one"))
		return 1;
	else if(!strcmp(str, "two"))
		return 2;
	else if(!strcmp(str, "three"))
		return 3;
	else if(!strcmp(str, "four"))
		return 4;
	else if(!strcmp(str, "five"))
		return 5;
	else if(!strcmp(str, "six"))
		return 6;
	else if(!strcmp(str, "seven"))
		return 7;
	else if(!strcmp(str, "eight"))
		return 8;
	else if(!strcmp(str, "nine"))
		return 9;
	else if(!strcmp(str, "zero"))
		return 0;
	else
		return -1;
}

int calc(int numA, int numB, char *op)
{
	int rval;

	if(op[0] == '+')
		rval = numA + numB;
	else if(op[0] == '-')
		rval = numA - numB;
	else if(op[0] == '*')
		rval = numA * numB;
	else
		rval = -1;

	return rval;
}

int checkAnswer(int num, char *str)
{
	int len, i, j, rval;
	char ans[11];

	memset(ans, 0x00, sizeof(char)*11);

	switch(num){
		case 0:
			strcpy(ans, "zero");
			break;
		case 1:
			strcpy(ans, "one");
			break;
		case 2:
			strcpy(ans, "two");
			break;
		case 3:
			strcpy(ans, "three");
			break;
		case 4:
			strcpy(ans, "four");
			break;
		case 5:
			strcpy(ans, "five");
			break;
		case 6:
			strcpy(ans, "six");
			break;
		case 7:
			strcpy(ans, "seven");
			break;
		case 8:
			strcpy(ans, "eight");
			break;
		case 9:
			strcpy(ans, "nine");
			break;
	}

	// compare(ans, str);

	len = strlen(ans);
	if(len != strlen(str)){
		return -1;
	}

	for(i=0; i<len; ++i){
		for(j=0; j<len; ++j){
			if(ans[i] == str[j]){
				str[j] = '\0';
				j=len;
			}
		}
		if(j==len)
			return -1;
	}


	return 0;
}

int process(void)
{
	char eq[80];
	char strA[10];
	char strB[10];
	char strC[10];
	char op[10];
	int numA;
	int numB;
	int numC;

	memset(eq, 0x00, sizeof(char)*80);

	fgets(eq, 80, stdin);

	strcpy(strA, strtok(eq, " "));
	strcpy(op, strtok(NULL, " "));
	strcpy(strB, strtok(NULL, " "));
	strcpy(strC, strtok(NULL, " = "));
	strC[strlen(strC)-1] = NULL;

	numA = cvtNum(strA);
	if(numA < 0){
		return -1;
	}
	numB = cvtNum(strB);
	if(numB < 0){
		return -1;
	}
	numC = calc(numA, numB, op);
	if(numC < 0){
		return -1;
	}

	return checkAnswer(numC, strC);

}

int main(void)
{
	int i, num;
	int rval;

	scanf("%d\n", &num);

	for(i=0; i<num; ++i){
		rval = process();
		if(rval==0)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
