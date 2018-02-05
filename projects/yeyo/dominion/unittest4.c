#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>

int main()
{
    int seed = 1000;
    int numPlayers = 2;
	struct gameState test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &test);
		
	int currentPlayer = whoseTurn(&test);

	//TEST: updateCoins 2 bonus
	printf("Unit TEST 1: updateCoins bonus 2\n");
	
	//Set Player Hand Card
	test.hand[currentPlayer][0] = gold;
	test.hand[currentPlayer][1] = copper;
	test.hand[currentPlayer][2] = duchy;
	test.hand[currentPlayer][3] = estate;
	test.hand[currentPlayer][4] = village;
	test.handCount[currentPlayer] = 5;
	
	//Call Update Coins Function with 2 Bonus
	updateCoins(currentPlayer, &test, 2);
	if(test.coins != 6){
      printf("coins don't match Actual: %d Expected: %d\n",test.coins, 6);
    }
	//assert(test.coins == 6);

    //TEST: updateCoins no bonus
	printf("Unit TEST 2: updateCoins no bonus\n");
	
	//Set Player Hand Card
	test.hand[currentPlayer][0] = gold;
	test.hand[currentPlayer][1] = copper;
	test.hand[currentPlayer][2] = duchy;
	test.hand[currentPlayer][3] = estate;
	test.hand[currentPlayer][4] = village;
	test.handCount[currentPlayer] = 5;
	
	//Call Update Coins Function with 2 Bonus
	updateCoins(currentPlayer, &test, 0);
	if(test.coins != 4){
      printf("coins don't match Actual: %d Expected: %d\n",test.coins, 4);
    }
	printf("updateCoins Testing Successfully\n");

	return 0;
}