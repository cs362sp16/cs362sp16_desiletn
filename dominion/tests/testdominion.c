/******************************************************************************
 * Dominon Tester
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../dominion.h"

#define ITERATIONS 2
#define K_MIN adventurer
#define K_MAX treasure_map

int _CARD[] = {
    curse,
    estate,
    duchy,
    province,
    copper,
    silver,
    gold,
    adventurer,
    council_room,
    feast,
    gardens,
    mine,
    remodel,
    smithy,
    village,
    baron,
    great_hall,
    minion,
    steward,
    tribute,
    ambassador,
    cutpurse,
    embargo,
    outpost,
    salvager,
    sea_hag,
    treasure_map
};

// Fill deck with unique cards
void initDeck(int *cards){
    int _CARDPICKED[27] = {0};

    for(int i = 0; i < 10; i++){
        while(1){
            int candidate = _CARD[rand() % 27];

            // If card not already selected
            if(_CARDPICKED[candidate] == 0){
                // Set card and mark as selected
                cards[i] = candidate;
                _CARDPICKED[candidate] = 1;

                break;
            }
        }
    }
}

// Setup new game
void initGameParams(int *numPlayers, int *cards, int seed, struct gameState *state){
    *numPlayers = (rand() % 3) + 2; // 2 to 4
    initDeck(cards);
    initializeGame(*numPlayers, cards, seed, state);
}

// Play a game of dominion until finished
void playDom(struct gameState *state){
    int player = whoseTurn(state);

    // Play card phase
    while(state->numActions){
        printf("While Action\n");
        int actionCards = 0;
        int handPos = 0;
        int card = 0;

        // Calculate number of actions available
        for(int i = 0; i < numHandCards(state); i++){
            if(state->hand[player][i] >= K_MIN && state->hand[player][i] <= K_MAX){
                actionCards++;
            }
        }

        // If actions available
        if(actionCards > 0){
            // Pick random card in hand
            handPos = rand() % state->handCount[player];
            card = state->hand[player][handPos];

            // If kingdom card
            if(card >= K_MIN && card <= K_MAX){
                printf("Card: %i\n", card);
                switch(card){
                    case feast:
                        playCard(handPos, )
                    case mine:
                        playCard(handPos, copper, silver, 0, state);
                        break;
                    case remodel:
                        playCard(handPos, copper, estate, 0, state);
                        break;
                    case steward:
                        playCard(handPos, 2, 0, 0, state);
                        break;
                    default:
                        playCard(handPos, 0, 0, 0, state);
                        break;
                }
            }
        }else{
            break;
        }
    }

    // Play buy phase
    updateCoins(player, state, NULL);
    while(state->coins && state->numBuys){
        printf("While Buy\n");
        int tmpCard;
        do{
            tmpCard = rand() % 27;
        }while(buyCard(tmpCard, state) != 0);
    }

    endTurn(state);
}

int main(int argc, char *argv[]){
    time_t seed = NULL;

    // Check argument for seed
    if(argc != 2){
        perror("Usage: ./testdominion [seed]\n");
        return 1;
    }

    seed = strtol(argv[1], NULL, 10);
    srand(time(&seed));

    printf("[Beginning Dominion tests]\n");
    for(int i = 0; i < ITERATIONS; i++){
        printf("test\n");
        if(i == 0){
            printf("%0.2f%% complete.", ((i + 1) / (float)ITERATIONS) * 100);
        }else{
            printf("\r%0.2f%% complete.", ((i + 1) / (float)ITERATIONS) * 100);
        }

        // Setup new game
        struct gameState state;
        int numPlayers = 0;
        int cards[10] = {0};
        initGameParams(&numPlayers, cards, seed, &state);

        // Play until finished
        while(!isGameOver(&state)){
            playDom(&state);
        }
    }

    printf("\n");

    return 0;
}
