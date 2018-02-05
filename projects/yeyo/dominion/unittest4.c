#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main()
{
    int seed = 1000;
    int numPlayers = 2;
	struct gameState test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &test);
		
	int currentPlayer = whoseTurn(&test);

	//TEST: updateCoins 2 bonus
	printf("Unit TEST : updateCoins bonus 2\n");
	
	//Set Player Hand Card
	control.hand[currentPlayer][0] = gold;
	control.hand[currentPlayer][1] = copper;
	control.hand[currentPlayer][2] = duchy;
	control.hand[currentPlayer][3] = estate;
	control.hand[currentPlayer][4] = village;
	control.handCount[currentPlayer] = 5;
	
	//Call Update Coins Function with 2 Bonus
	updateCoins(currentPlayer, &test, 2);

	assert(test->coins == 6);

	printf("updateCoins Testing Successfully\n");

	return 0;
}