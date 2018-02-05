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

	//Unit TEST 1: discardCard-> last card in hand array is played
	printf("Unit TEST 1: discardCard trashFlag < 1 \n");
	//set currentPlayer's hand and deck
	test.hand[currentPlayer][0] = silver;
	test.hand[currentPlayer][1] = silver;
	test.hand[currentPlayer][2] = silver;
	test.hand[currentPlayer][3] = silver;
	test.hand[currentPlayer][4] = silver;
	test.handCount[currentPlayer] = 5;
	int discardCount = test.discardCount[currentPlayer];
	
	discardCard(4, currentPlayer, &test, 0);
	assert(test.handCount[currentPlayer] == 4);
	assert(test.discardCount[currentPlayer] == discardCount+1);
	
	
	//Unit TEST 2: discardCard only one card in hand
	printf("Unit TEST 2: discardCard only one card in hand \n");
	test.hand[currentPlayer][0] = copper;
	test.handCount[currentPlayer] = 1;
	discardCount = test.discardCount[currentPlayer];
	
	discardCard(1, currentPlayer, &test, 0);
	
	assert(test.handCount[currentPlayer] == 0);
	assert(test.discardCount[currentPlayer] == discardCount+1);
	
	//Unit TEST 3: discardCard trashFlag <1
	printf("Unit TEST 3: Unit TEST 3: discardCard trashFlag <1 \n");
	test.hand[currentPlayer][0] = silver;
	test.hand[currentPlayer][1] = silver;
	test.hand[currentPlayer][2] = silver;
	test.hand[currentPlayer][3] = silver;
	test.hand[currentPlayer][4] = silver;
	test.handCount[currentPlayer] = 5;
	int playedCardCount = test.playedCardCount;
	discardCount = test.discardCount[currentPlayer];
	
	discardCard(2, currentPlayer, &test, 1);
	assert(test.handCount[currentPlayer] == 4);
	assert(test.discardCount[currentPlayer] == discardCount+1);
	assert(test.playedCardCount == playedCardCount+1);
	
	
	//Unit TEST 4: discardCard
	printf("Unit TEST 4: Unit TEST 3: discardCard trashFlag <1 \n");
	test.hand[currentPlayer][0] = silver;
	test.hand[currentPlayer][1] = silver;
	test.hand[currentPlayer][2] = silver;
	test.hand[currentPlayer][3] = silver;
	test.hand[currentPlayer][4] = silver;
	test.handCount[currentPlayer] = 5;
	discardCount = test.discardCount[currentPlayer];
	int lastCard = test.hand[currentPlayer][state->handCount[currentPlayer] - 1]
	
	
	discardCard(2, currentPlayer, &test, 1);
	assert(test.handCount[currentPlayer] == 4);
	assert(test.discardCount[currentPlayer] == discardCount+1);
	assert(state->hand[currentPlayer][2] == lastCard);
	printf("discardCard Testing Successfully\n");

	return 0;
}