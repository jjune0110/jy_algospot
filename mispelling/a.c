#include <stdio.h>
#include <string.h>


int process(int num)
{
	int index;
	char text[128];
	char tempStr[128];

	
	memset(text, 0x00, sizeof(char)*128);
	memset(tempStr, 0x00, sizeof(char)*128);

	scanf("%d %s", &index, text);

	if(index < 0)
		return -1;
	if(strlen(text) < index)
		return -1;

	strncpy(tempStr, text, index-1);
	strcat(tempStr, &text[index]);

	printf("%d %s\n", num+1, tempStr);

	return 0;
}

int main(void)
{
	int C;
	int i;

	scanf("%d", &C);

	for(i=0; i<C; ++i){
		process(i);
	}

	return 0;
}
