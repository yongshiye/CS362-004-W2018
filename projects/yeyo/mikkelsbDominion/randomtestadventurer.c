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

    printf("\nTESTING ADVENTURER CARD:\n");

    printf ("----  -RANDOM TESTS- ----\n");
    int testFailed = 0;

    for (int i = 0; i < RANDOM_TEST_MAX; i++){
    	int numPlayers = (rand() % 3)+2;;
    	int currentPlayer = 0;

    	//initialize game 
    	initializeGame(numPlayers, k, rand(), &test);
		test.whoseTurn = rand() % test.numPlayers;
		currentPlayer = whoseTurn(&test);

		test.handCount[currentPlayer] = (rand() % (MAX_HAND/numPlayers))+1;
        test.deckCount[currentPlayer] = (rand() % (MAX_DECK/numPlayers))+1;
        test.discardCount[currentPlayer] = (rand() % (MAX_DECK/numPlayers))+1;

        int handCount = test.handCount[currentPlayer];
    	int total = test.deckCount[currentPlayer] + test.discardCount[currentPlayer];

        int j;
        for (j = 0; j < test.handCount[currentPlayer]; j++) {
            if (rand() % 2 == 0) test.hand[currentPlayer][j] = silver;
            else test.hand[currentPlayer][j] = cutpurse;
        }
        for (j = 0; j < test.deckCount[currentPlayer]; j++) {
            if (rand() % 2 == 0) test.deck[currentPlayer][j] = copper;
            else test.deck[currentPlayer][j] = estate;
        }

        int temphand[1000] = {}; 
    	int z = 0;
    	int drawTressure = rand() % 3;


    	//Count Tressure Cards will be draw
    	int count = drawTressure;
    	int addedCard=0;
    	int deckCounter = test.deckCount[currentPlayer];
    	while(count<2){
    		if (test.deck[currentPlayer][deckCounter - 1] == copper){
    			addedCard++;
    			count++;
    		}
    		deckCounter--;
    	}

        //Test adventurer Card
        int cardDrawn = copper;
        adventurerCardEffect(&drawTressure,&test,&currentPlayer,&temphand,&z,&cardDrawn);
	    //adventurerCardEffect(drawTressure,temphand,z,currentPlayer,&test);
	    printf("Check Players State %d\n", i);
	    if(test.deckCount[currentPlayer] + test.discardCount[currentPlayer] != total - addedCard){
	    	testFailed = 1;
	      	printf("Total Count don't match Actual: %d Expected: %d\n",test.discardCount[currentPlayer] + test.deckCount[currentPlayer], total);
	    }
	    
	    if(test.handCount[currentPlayer] != handCount + addedCard){
	    	testFailed = 1;
	      	printf("handCount don't match Actual: %d Expected: %d\n",test.handCount[currentPlayer], handCount + addedCard);
	    }
    }

    if(testFailed){
		printf("\nRandom TESTING ADVENTURER CARD Failed\n");
    }else{
    	printf("\nRandom TESTING ADVENTURER CARD Successfully\n");
    }
    return 0;
}