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
    int otherPlayer = 1;
    //initialize game
    initializeGame(numPlayers, k, seed, &test);
    printf("---------- Testing council room card ----------\n"); 
  
    int handCount = test.handCount[currentPlayer];
    int deckCount = test.deckCount[currentPlayer];
    int numBuys = test.numBuys;

    int otherPlayerHandCount = test.handCount[otherPlayer];
    int otherPlayerHDeckCount = test.deckCount[otherPlayer];

    //Testing council room card
    int handPos =0;
    councilRoomCardEffect(&test,&currentPlayer,&handPos);
    printf("Check Players State\n");
    assert(test.handCount[currentPlayer] == handCount + 3);
    assert(test.deckCount[currentPlayer] == deckCount - 4);
    assert(test.numBuys == numBuys + 1);

    printf("check other players state\n");
    assert(test.handCount[otherPlayer] == otherPlayerHandCount + 1);
    assert(test.deckCount[otherPlayer] == otherPlayerHDeckCount - 1);
    printf("\n---------- Testing council room Successfully ----------\n"); 
    return 0;
}