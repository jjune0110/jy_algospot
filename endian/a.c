#include <stdio.h>
#include <string.h>

unsigned int process(int num)
{
	unsigned char ch[4];
	unsigned char newCh[4];
	unsigned char temp;
	unsigned int conv=0;
	int i=0;

	memset(ch, 0x00, sizeof(char)*4);
	memset(newCh, 0x00, sizeof(char)*4);

	memcpy(ch, &num, sizeof(int));

	for(i=0; i<4; ++i){
		newCh[i] = (ch[3-i]&0x0F<<4) + (ch[3-i]&0xF0>>4);
	}

	memcpy(&conv,newCh, sizeof(int));

	return conv;
}

int main(void)
{
	int C;
	int i;
	unsigned int num;
	unsigned int rval=0;

	scanf("%d", &C);

	for(i=0; i<C; ++i){
		scanf("%d",&num);
		rval = process(num);
		printf("%u\n",rval);
	}

	return 0;
}
