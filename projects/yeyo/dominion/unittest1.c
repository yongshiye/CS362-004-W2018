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
	int nextPlayer = (currentPlayer+1)%2;
	//Unit TEST 1: endTurn
	printf("Unit TEST 1: endTurn\n");
	
	//set currentPlayer's hand and deck
	test.hand[currentPlayer][0] = copper;
	test.hand[currentPlayer][1] = copper;
	test.hand[currentPlayer][2] = copper;
	test.hand[currentPlayer][3] = copper;
	test.hand[currentPlayer][4] = copper;
	test.handCount[currentPlayer] = 5;

	test.deck[nextPlayer][0] = copper;
	test.deck[nextPlayer][1] = copper;
	test.deck[nextPlayer][2] = copper;
	test.deck[nextPlayer][3] = copper;
	test.deck[nextPlayer][4] = copper;
	test.deckCount[nextPlayer] = 5;
	test.handCount[nextPlayer] = 0;

	endTurn(&test);
	
	assert(test.outpostPlayed == 0);
	assert(test.whoseTurn == nextPlayer);
	assert(test.phase == 0);
	assert(test.numActions  == 1);
	assert(test.coins == 5);
	assert(test.numBuys == 1);
	
	printf("endTurn Testing Successfully\n");

	return 0;
}