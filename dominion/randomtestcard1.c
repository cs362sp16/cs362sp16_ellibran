#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
	
	printf("TEST 1\n");
	
	int seed, test_max, player_count, player, deck_count, hand_count, turn, i;
	
	struct gameState g;
	
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
	printf("TEST 2\n");
	
	if(argc = 3){
		seed = 42;
		test_max = 10;
	}else {
		printf("USAGE: [Program Name] [Seed] [Number of Tests]\n");
		return 0;
	}
	
	printf("TEST 3\n");
	
	for(i = 0; i < test_max; i++){		
		printf("TEST 4\n");
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