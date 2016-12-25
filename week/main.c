#include <stdio.h>
#include <string.h>

int getDate(char *name)
{
	int rval;

	if(!strcmp(name, "Sunday")){
		rval = 0;
	}
	else if(!strcmp(name, "Monday")){
		rval = 1;
	}
	else if(!strcmp(name, "Tuesday")){
		rval = 2;
	}
	else if(!strcmp(name, "Wednesday")){
		rval = 3;
	}
	else if(!strcmp(name, "Thursday")){
		rval = 4;
	}
	else if(!strcmp(name, "Friday")){
		rval = 5;
	}
	else if(!strcmp(name, "Saturday")){
		rval = 6;
	}
	else{
		rval = -1;
	}

	return rval;
}
	
int isValidMonth(int month)
{
	int max;

	switch(month){
		case 0:
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			max = 31;
			break;

		case 2:
			max = 28;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			max = 30;
			break;

		default:
			max = -1;
			break;
	}

	return max;
}

int process(void)
{
	int i;
	int rval;
	int max;
	int min;
	int date;
	int today;
	int month;
	int day;
	char name[16];
	char ans[1024];

	memset(name, 0x00, sizeof(char)*16);
	memset(ans, 0x00, sizeof(char)*1024);

	scanf("%d %d %s\n", &month, &day, name);

	max = isValidMonth(month);
	min = isValidMonth(month-1);
	rval = getDate(name);

	if(max < 0 || min < 0 || rval < 0)
		return -1;
	
	if(day > max)
		return -1;

	date = day - rval;


	// sunday
	if(date < 1)
		today = min + date;
	else
		today = date;

	rval = sprintf(ans, "%d ", today);

	for(i=1; i<7; ++i){
		if(date < 1)
			today = min + date + i;
		else
			today = date + i;
		if(day < 15){
			if(today > min)
				today -= min;
		}
		else if(day >= 15){
			if(today > max)
				today -= max;
		}

		rval += sprintf(&ans[rval], "%d ", today);
	}

	rval += sprintf(&ans[rval-1],"\n");

	printf("%s", ans);

	return 0;
}

int main(void)
{
	int i;
	int num;
	int rval;

	scanf("%d\n", &num);

	for(i=0; i<num; ++i){
		rval = process();
		if(rval < 0)
			break;
	}

	return 0;
}

