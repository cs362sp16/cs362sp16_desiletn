/******************************************************************************
 * Random Test Card 1 - Smithy
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "../dominion.h"

#define ITERATIONS 10000

int main(int argc, char *argv[]){
    struct gameState state;
    time_t seed = NULL;
    int cards[10] = {
        smithy,
        adventurer,
        gardens,
        embargo,
        cutpurse,
        mine,
        ambassador,
        outpost,
        baron,
        tribute
    };

    // Check arguments
    if(argc != 2){
        printf("Usage: ./randomtestcard2 SEED\n");
        return 1;
    }

    // Get and set seed
    seed = strtol(argv[1], NULL, 10);
    srand(time(&seed));

    printf("Random testing card (10000x): Smithy.\n");

    // Run tests
    for(int i = 0; i < ITERATIONS; i++){
        int players = rand() % MAX_PLAYERS;
        int randNum = rand();
        int currPlayer = 0;
        int savedHandCount = NULL;
        int result = NULL;

        // Init new game
        initializeGame(players, cards, randNum, &state);

        // Setup state
        state.deckCount[currPlayer] = rand() % MAX_DECK;
        state.discardCount[currPlayer] = rand() %  MAX_DECK;
        state.handCount[currPlayer] = rand() %  MAX_HAND;

        // Save values to be affected by smithy
        savedHandCount = state.handCount[currPlayer];

        // Play council room card
        cardEffect(council_room, NULL, NULL, NULL, &state, 0, NULL);

        // Check affected values against saved ones
        myAssertTrue((result == 0), "Card effect function.");
        myAssertTrue((savedHandCount + 3 == state.handCount[currPlayer]), "Post hand count.");
    }

    checkAsserts();

    return 0;
}
