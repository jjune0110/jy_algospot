#include <stdio.h>
#include <string.h>

#define NUM_TEAM	8
#define LEN_TEAM	32

#define MAX_REMAIN	25

char	myTeam[LEN_TEAM];
char	team[NUM_TEAM][LEN_TEAM];
int		win[NUM_TEAM];
int		draw[NUM_TEAM];
int		lost[NUM_TEAM];

int		remain;
char	team1[MAX_REMAIN][LEN_TEAM];
char	team2[MAX_REMAIN][LEN_TEAM];
float	rate[NUM_TEAM];


int checkTeamName(char *t)
{
	int i;

	for(i=0; i<NUM_TEAM; ++i){
		if(!strcmp(t, team[i]))
			break;
	}

	if(i==NUM_TEAM)
		return -1;

	return i;
}

int readTeam(void)
{
	int		i;

	for(i=0; i<NUM_TEAM; ++i){
		scanf("%s %d %d %d", team[i], &win[i], &draw[i], &lost[i]);
	}

	// for debug
	/*
	for(i=0; i<NUM_TEAM; ++i){
		printf("%s %d %d %d\n", team[i], win[i], draw[i], lost[i]);
	}
	*/

	return 0;
}

int checkMyTeam(void)
{
	int rval;

	scanf("%s", myTeam);
	
	// for debug
	/*
	printf("myTeam : '%s'\n", myTeam);
	*/
	rval = checkTeamName(myTeam);

	return rval;
}

int checkRemainGame(void)
{
	int i;
	int rval;

	scanf("%d", &remain);

	if(remain > MAX_REMAIN)
		return -1;

	for(i=0; i<remain; ++i){
		scanf("%s %s", team1[i], team2[i]);
		rval = checkTeamName(team1[i]);
		if(rval < 0)
			return -1;
		rval = checkTeamName(team2[i]);
		if(rval < 0)
			return -1;
	}

	// for Debug
	for(i=0; i<remain; ++i)
		printf("%s %s\n", team1[i], team2[i]);

	return 0;
}

int calcWin(void)
{
	int i;
	int tot;

	for(i=0; i<NUM_TEAM; ++i){
		tot = win[i] + draw[i] + lost[i];
		rate[i] = (float)(win[i]) / (float)(tot);
	}

	// for debug
	for(i=0; i<NUM_TEAM; ++i){
		printf("%s %d %d %d %f\n", team[i], win[i], draw[i], lost[i], rate[i]);
	}

	return 0;
}

int calcRate(float pRate[], int pIdx)
{
	int i;
	int rval;
	int t1Idx, t2Idx;
	float rRate[NUM_TEAM];

	t1Idx = checkTeamName(team1[pIdx]);
	t2Idx = checkTeamName(team2[pIdx]);


	for(i=0; i<NUM_TEAM; ++i){
		rRate[i] = pRate[i];
	}

	/* if team1 win */
	++win[t1Idxa];	


	/* else team2 win */

	return 0;
}


int process(void)
{
	int i;
	int rval;

	readTeam();

	rval = checkMyTeam();
	if(rval < 0){
		printf("error\n");
		return -1;
	}

	checkRemainGame();

	calcWin();

	/* calc remain game */
	calcRate(rate, 0);


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
