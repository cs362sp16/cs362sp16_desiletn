/******************************************************************************
 * Unit Test 2
 * Checks to see if game state is successfully created
 * Primary tested function: shuffle()
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
    struct gameState game1;
    struct gameState game2;

    // Init unshuffled and unshuffled game
    initializeGame(numPlayers, kingdomCards, seed, &game1);
    initializeGame(numPlayers, kingdomCards, seed, &game2);
    shuffle(0, &game2);

    // Compare cards between the two decks
    float deckSize = sizeof(game1.deck);
    float differences = 0;
    for(int i = 0; i < deckSize; i++){
        if(game1.deck[0][i] != game2.deck[0][i]){
            differences++;
        }
    }

    // Ensure shuffled deck is at least 80% different
    myAssertTrue((differences / deckSize >= 0.80), "Decks are adequately shuffled.");

    checkAsserts();
}
