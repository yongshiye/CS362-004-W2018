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

	//Unit TEST 1: isGameOver Province cards is empty
	printf("Unit TEST 1: isGameOver Province cards is empty \n");
	control.supplyCount[province] = 0;
	assert(isGameOver(&test) == 1);
	
	
	//Unit TEST 2: isGameOver three supply pile are at 0
	printf("Unit TEST 1: isGameOver three supply pile are at 0 \n");
	control.supplyCount[province] = 0;
	control.supplyCount[smithy] = 0;
	control.supplyCount[adventurer] = 0;
	assert(isGameOver(&test) == 1);
	
	//Unit TEST 2: isGameOver three supply pile are at 0
	printf("Unit TEST 1: isGameOver three supply pile are at 0 \n");
	control.supplyCount[province] = 5;
	control.supplyCount[smithy] = 5;
	control.supplyCount[adventurer] = 5;
	assert(isGameOver(&test) == 0);
	
	printf("isGameOver Testing Successfully\n");

	return 0;
}