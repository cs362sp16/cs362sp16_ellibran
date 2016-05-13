#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
	int seed, test_max, player_count, player, deck_count, hand_count, turn, i;
	
	struct gameState g;
	
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
	if(argc = 3){
		seed = atoi(argv[1]);
		test_max = atoi(argv[2]);
	}else {
		printf("USAGE: [Program Name] [Seed] [Number of Tests]\n");
		exit(0);
	}
	
	for(i = 0; i < test_max; i++){		
		player_count = rand() %3 + 2;
		
		initializeGame(player_count, k, seed, &g);
	
		//choosing which player to test
		player = rand() % player_count;
		deck_count = rand() % MAX_DECK;
		hand_count = rand() % MAX_HAND;
		
		g.whoseTurn = player;
		g.deckCount[player] = deck_count;
		g.handCount[player] = hand_count;
		
		cardEffect(smithy, 1, 1, 1, &g);
		
		printf("Smithy Test #%d: Players [%d] Player [%d] Deck Count [%d] Hand Count [%d]\n", player_count, player, deck_count, hand_count);		
	}
}