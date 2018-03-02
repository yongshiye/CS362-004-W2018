#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main()
{
    struct gameState test;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
   	int numPlayers = 2;
   	int seed = 1000;

   	int currentPlayer = 0;
   	//initialize game
   	initializeGame(numPlayers, k, seed, &test);
   	printf("---------- Testing smithy card ----------\n"); 
 	
   	int handCount = test.handCount[currentPlayer];
   	int deckCount = test.deckCount[currentPlayer];
   	
   	//Test smithy card
   	smithyCardEffect(currentPlayer,&test,0);
   	printf("Check Players State\n");
   	assert(test.handCount[currentPlayer] == handCount + 2);
   	assert(test.deckCount[currentPlayer] == deckCount - 3);

    printf("\n---------- Testing smithy card Successfully----------\n"); 
    return 0;
}