#include <stdio.h>
#include <string.h>

#define MSG_LEN	7

int decode(char message[])
{
	int i;

	int bit1;
	int bit2;
	int bit3;

	bit1 = message[0] ^ message[2] ^ message[4] ^ message[6];	// 1^3^5^7
	bit2 = message[1] ^ message[2] ^ message[5] ^ message[6];	// 2^3^6^7
	bit3 = message[3] ^ message[4] ^ message[5] ^ message[6];	// 4^5^6^7

//	printf("[%s:%d] %d %d %d\n", __FUNCTION__, __LINE__, bit1, bit2, bit3);
	
	return bit1*1 + bit2*2 + bit3*4;
}

int process(void)
{
	char message[MSG_LEN];
	int rval;

	memset(message, 0x00, sizeof(char)*MSG_LEN);

	scanf("%s", message);
	message[MSG_LEN] = '\0';

//	printf("[%s:%d] '%s'\n", __FUNCTION__, __LINE__, message);

	rval = decode(message);

	message[rval-1] = message[rval-1] ^ 1;

	printf("%c%c%c%c\n", message[2], message[4], message[5], message[6]);

	return 0;
}


int main(void)
{
	int num;		// test case
	int i;

	scanf("%d", &num);

	for(i=0; i<num; ++i){
		process();
	}

	return 0;
}
