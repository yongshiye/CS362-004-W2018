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
    printf("---------- Testing adventurer card ----------\n"); 
  
    int handCount = test.handCount[currentPlayer];
    int deckCount = test.deckCount[currentPlayer];
    int discardCount = test.discardCount[currentPlayer];

    int temphand[1000] = {}; 
    int z = 0;
    //Set Up Deck
    int deckCounter = test.deckCount[currentPlayer];
    test.deck[currentPlayer][deckCounter - 1] = copper;
    test.deck[currentPlayer][deckCounter - 2] = cutpurse;
    test.deck[currentPlayer][deckCounter - 3] = silver;

    //Test adventurer Card
    adventurerCardEffect(0,temphand,z,currentPlayer,&test);
    printf("Check Players State\n");
    assert(test.handCount[currentPlayer] == handCount + 2);
    if(test.deckCount[currentPlayer] != deckCount - 3){
      printf("deckCount don't match Actual: %d Expected: %d\n",test.deckCount[currentPlayer], deckCount - 3);
    }
    if(test.discardCount[currentPlayer] != discardCount + 1){
      printf("discardCount don't match Actual: %d Expected: %d\n",test.discardCount[currentPlayer], discardCount + 1);
    }

    printf("\n---------- Testing adventurer Successfully ----------\n"); 
    return 0;
}