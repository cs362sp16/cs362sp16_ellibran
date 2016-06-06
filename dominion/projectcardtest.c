////////////////////////
//project Unit Test
//refac_great_hall
////////////////////////

#include "dominion.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>

int player = 1;
int failed = 0;

int assert_card_num(int b) {
  if (b == 0) {
    printf("refac_great_hall Number of Cards Failure\n");
    failed = 1;
  }
}

int assert_actions(int b) {
  if (b == 0) {
    printf("refac_great_hall Number of Actions Failure\n");
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("refac_great_hall Successful\n");
  }
}

int main()
{
	struct gameState g;
	int pre_card_num, pre_numActions, post_card_num, post_numActions;
	
	int k[10] = {smithy,great_hall,salvager,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	initializeGame(2, k, 5, &g);
	
	g.whoseTurn = player;
	g.deckCount[player] = 4;
	g.handCount[player] = 0;
	
	pre_card_num = g.handCount[player];
	pre_numActions = g.numActions;
	
	addCardToHand(player, great_hall, &g);
	playCard(hand_count, 0, 0, 0, &g);
	
	post_card_num = g.handCount[player];
	post_numActions = g.numActions;
	
	if(pre_card_num == post_card_num){
		assert_card_num(1);
	} else {
		assert_card_num(0);
	}
	
	if(pre_numActions != post_numActions){
		assert_actions(1);
	} else {
		assert_actions(0);
	}

	checkasserts();
}