/******************************************************************************
 * Unit Test 3
 * Checks to see if playCard() works correctly
 * Primary tested function: playCard()
 ******************************************************************************/
#include <stdio.h>
#include "assert.h"
#include "../dominion.h"

int main(int argc, char *argv[]){
    // Game init variables
    int numPlayers = 1;
    int kingdomCards[] = {smithy,adventurer,gardens,embargo,cutpurse,mine,
                          ambassador,outpost,baron,tribute};
    int seed = 1234;
    struct gameState g1;
    struct gameState *game1 = &g1;

    // Init unshuffled and unshuffled game
    initializeGame(numPlayers, kingdomCards, seed, game1);

    // Shuffle and check exit code
    int result = playCard(2, -1, -1, -1, game1);
    myAssertTrue((result == 0), "Playing a card.");

    checkAsserts();
}
