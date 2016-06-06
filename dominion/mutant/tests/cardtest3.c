/******************************************************************************
 * Card test 3
 * Tests functionality of the smithy card
 ******************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "../dominion.h"

int main(int argc, char *argv[]){
    // Game init variables
    int numPlayers = 2;
    int kingdomCards[] = {smithy,adventurer,gardens,embargo,cutpurse,mine,
                          ambassador,outpost,baron,tribute};
    int seed = 1234;
    struct gameState g1;
    struct gameState *game1 = &g1;

    // Init unshuffled and unshuffled game
    initializeGame(numPlayers, kingdomCards, seed, game1);

    int numCardsStart = numHandCards(game1);

    int result = cardEffect(smithy, NULL, NULL, NULL, game1, 0, NULL);
    myAssertTrue((result == 0), "Smithy card effects.");

    int numCardsPost = numHandCards(game1);

    myAssertTrue((numCardsPost == (numCardsStart + 3)), "Three cards drawn.");

    checkAsserts();
}
