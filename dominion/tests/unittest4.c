/******************************************************************************
 * Unit Test 4
 * Checks to see if supplyCount() works correctly
 * Primary tested function: supplyCount()
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

    // Check supply counts for silver, copper, gold cards
    int result = supplyCount(copper, game1);
    myAssertTrue((result == 46), "Copper card supply count.");

    result = supplyCount(silver, game1);
    myAssertTrue((result == 40), "Silver card supply count.");

    result = supplyCount(gold, game1);
    myAssertTrue((result == 30), "Gold card supply count.");

    checkAsserts();
}
