#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cvtNum(char *str)
{
	int i;
	int len;
	int rval;
	int temp1, temp2;

	/*
	len = strlen(str);
	if(len != 2)
		return -1;

	rval = 0;
	temp1 = 0;
	temp2 = 0;
	for(i=0; i<len; ++i){
		if(str[i] >= '0' && str[i] <= '9'){
			temp1 = str[i]-'0'; 
		}
		else if(str[i] >= 'a' &&  str[i] <= 'f'){
			temp1 = str[i] - 'a' + 10;
		}
		else{
			temp1 = -1;
		}

		if(i==0)
			temp2 += temp1 * 16;
		else
			temp2 += temp1;
	}
	*/

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


void process(void)
{
	int i,j;
	int len;
	int tempInt;
	char str[128];
	char newStr[128];
	char temp[3];


	memset(str, 0x00, sizeof(char)*128);
	memset(newStr, 0x00, sizeof(char)*128);

	fgets(str, 80, stdin);

	len = strlen(str);

	j=0;
	for(i=0; i<len; ++i){
		if(str[i] == '%'){
			memset(temp, 0x00, sizeof(char)*3);
			strncpy(temp, &str[i+1], 2);
			tempInt = cvtNum(temp);
			if(tempInt > 0){
				newStr[j++] = (char)tempInt;
				i+=2;
			}
			else{
				newStr[j++] = str[i];
			}
		}
		else{
			newStr[j++] = str[i];
		}
	}

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
