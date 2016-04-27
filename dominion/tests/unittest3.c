/******************************************************************************
 * Unit Test 3
 * Checks to see if player has correct copper, silver, gold cards at start
 * Primary tested function: fullDeckCount()
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

    // Check copper cards
    int result = fullDeckCount(1, copper, game1);
    myAssertTrue((result == 7), "Seven copper cards.");

    // Check silver cards
    result = fullDeckCount(1, silver, game1);
    myAssertTrue((result == 0), "Zero silver cards.");

    // Check gold cards
    result = fullDeckCount(1, gold, game1);
    myAssertTrue((result == 0), "Zero gold cards.");

    checkAsserts();
}
