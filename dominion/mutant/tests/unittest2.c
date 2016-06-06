/******************************************************************************
 * Unit Test 2
 * Checks to see if player has 5 cards at start
 * Primary tested function: numHandCards()
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

    // Check player hand at start
    int result = numHandCards(game1);
    myAssertTrue((result == 5), "Player has 5 cards at start.");

    checkAsserts();
}
