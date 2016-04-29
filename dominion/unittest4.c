////////////////////////
//buyCard Unit Test
////////////////////////

#include "dominion.h"
#include <stdio.h>

int failed = 0;

int myassert(int b,char* msg) {
  if (b == 0) {
    printf("buyCard Test Failure: %s\n",msg);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("buyCard Successful\n");
  }
}

int main()
{
	struct gameState g;
	int r1, r2, r3;

	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	initializeGame(2, k, 5, &g);
	
	r1 = buyCard (1, &g);
	myassert(r == 0, "buyCard, should return valid 0");
	
	r2 = buyCard(42, &g);
	myassert(r == -1, "buyCard, should return invalid -1, card doesn't exist");
	
	r3 = buyCard(1, &g);
	myassert(r == -1, "buyCard, should return invalid -1, player out of money");

	
	checkasserts();
}