////////////////////////
//numHandCards Unit Test
////////////////////////

#include "dominion.h"

int failed = 0;

int myassert(int b,char* msg) {
  if (b == 0) {
    printf("numHandCards Test Failure: %s\n",msg);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("numHandCards Successful\n");
  }
}

int main()
{
	struct gameState g;
	struct gameState *p = &g;

	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

	initializeGame(2, k, 5, &g);
	
	r = numHandCards(p);
	myassert(r == 5, "numHandCards, should return valid 5");
	
	checkasserts();
}