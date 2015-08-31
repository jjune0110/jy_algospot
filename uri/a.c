#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cvtNum(char *str)
{
	int i;
	int len;
	int rval;
	int temp1, temp2;

	if(!strcmp(str, "20"))
		temp2 = 32;
	else if(!strcmp(str, "21"))
		temp2 = 33;
	else if(!strcmp(str, "24"))
		temp2 = 36;
	else if(!strcmp(str, "25"))
		temp2 = 37;
	else if(!strcmp(str, "28"))
		temp2 = 40;
	else if(!strcmp(str, "29"))
		temp2 = 41;
	else if(!strcmp(str, "2a"))
		temp2 = 42;
	else
		temp2 = 0;

	return temp2;
}

void checkStr(char *orgStr, char *newStr)
{
	int i,j;
	int len;
	int tempInt;
	char temp[3];

	memset(newStr, 0x00, sizeof(char)*128);
	len = strlen(orgStr);

	j=0;
	for(i=0; i<len; ++i){
		if(orgStr[i] == '%'){
			memset(temp, 0x00, sizeof(char)*3);
			strncpy(temp, &orgStr[i+1], 2);
			tempInt = cvtNum(temp);
			if(tempInt > 0){
				newStr[j++] = (char)tempInt;
				i+=2;
			}
			else{
				newStr[j++] = orgStr[i];
			}
		}
		else{
			newStr[j++] = orgStr[i];
		}
	}

}

void process(void)
{
	char str[128];
	char newStr[128];
	int  isFirst=0;


	memset(str, 0x00, sizeof(char)*128);
	memset(newStr, 0x00, sizeof(char)*128);

	fgets(str, 80, stdin);

	do{
		if(isFirst){
			strcpy(str, newStr);
		}
		checkStr(str, newStr);
		isFirst = 1;
	}while(strcmp(str, newStr) != 0);

	printf("%s", newStr);
}


int main(void)
{
	int num;
	int i;

	scanf("%d\n", &num);
	if(num <1 || num > 100)
		return 0;

	for(i=0; i<num; ++i){
		process();
	}

	return 0;
}
