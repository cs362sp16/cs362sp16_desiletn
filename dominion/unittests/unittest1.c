/******************************************************************************
 * Unit Test 1
 * Checks to see if game state is successfully created
 * Primary tested function: initializeGame()
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

    // Init game and test
    int result = initializeGame(numPlayers, kingdomCards, seed, game1);
    myAssertTrue((result == 0), "Game state initialization.");

    checkAsserts();
}
