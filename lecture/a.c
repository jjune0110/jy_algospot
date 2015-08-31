#include <stdio.h>
#include <string.h>

int process(void)
{
	char org[1024];
	char newStr[1024];

	char temp1[3], temp2[3];

	int len;
	int subStr;

	int i,j;

	scanf("%s", &org);

	strcpy(newStr, org);

	len = strlen(org);
	subStr = len/2;

	for(i=0; i<subStr; ++i){
		strncpy(temp1, &newStr[i*2], 2);
		temp1[2] = '\0';
		for(j=i+1; j<subStr; ++j){
			strncpy(temp2, &newStr[j*2], 2);
			temp2[2] = '\0';

			if(strcmp(temp1, temp2) > 0){
				strncpy(&newStr[i*2], temp2, 2);
				strncpy(&newStr[j*2], temp1, 2);
				strcpy(temp1, temp2);
			}
		}
	}

	printf("%s\n", newStr);

	return 0;
}

int main(void)
{
	int i;
	int C;

	scanf("%d", &C);

	for(i=0; i<C; ++i){
		process();
	}

	return 0;
}

