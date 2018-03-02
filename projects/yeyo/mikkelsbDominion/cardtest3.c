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
    printf("---------- Testing village card ----------\n"); 
  
    int handCount = test.handCount[currentPlayer];
    int deckCount = test.deckCount[currentPlayer];
    int numActions = test.numActions;
    
    //Testing village card
    int bonus = 0;
    cardEffect(village,0 ,0 ,0 , &test, 0, &bonus);
    printf("Check Players State\n");
    assert(test.handCount[currentPlayer] == handCount);
    assert(test.deckCount[currentPlayer] == deckCount - 1);
    assert(test.numActions == numActions + 2);

    printf("\n---------- Testing village card Successfully----------\n"); 
    return 0;
}