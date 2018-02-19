#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "time.h"

#define RANDOM_TEST_MAX 1000

int main()
{
    struct gameState test;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    srand(time(NULL));

    printf("\n====TESTING VILLAGE CARD:====\n");

    printf ("========RANDOM TESTS=========\n");
    int testFailed = 0;

    for (int i = 0; i < RANDOM_TEST_MAX; i++){
    	int numPlayers = (rand() % 3)+2;
    	int currentPlayer = 0;

    	//initialize game 
    	initializeGame(numPlayers, k, rand(), &test);
		test.whoseTurn = rand() % test.numPlayers;
		currentPlayer = whoseTurn(&test);
	
		test.handCount[currentPlayer] = (rand() % (MAX_HAND/numPlayers))+1;
        test.deckCount[currentPlayer] = (rand() % (MAX_DECK/numPlayers))+1;

        int handPos = rand() % test.handCount[currentPlayer];

        int handCount = test.handCount[currentPlayer];
    	int deckCount = test.deckCount[currentPlayer];
    	//int discardCount = test.discardCount[currentPlayer];
    	int numActions = test.numActions;
    	villageCardEffect(currentPlayer,&test,handPos);
   		printf("Check Players State %d\n", i);
   		if(test.handCount[currentPlayer] != handCount ){
   			testFailed = 1;
   			printf("handCount don't match Actual: %d Expected: %d\n",test.handCount[currentPlayer], handCount + 2);
   		}
   		if(test.deckCount[currentPlayer] != deckCount - 1 ){
   			testFailed = 1;
   			printf("deckCount don't match Actual: %d Expected: %d\n",test.deckCount[currentPlayer], deckCount - 3);
   		}
   		if(test.numActions != numActions + 2){
	    	testFailed = 1;
	      	printf("numActions don't match Actual: %d Expected: %d\n",test.numActions , numActions + 2);
	    }

    }
    if(testFailed){
		printf("\nnRandom TESTING VILLAGE CARD Failed:\n");
    }else{
    	printf("\nRandom TESTING VILLAGE CARD Successfully\n");
    }
    return 0;
}