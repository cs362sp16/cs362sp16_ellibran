////////////////////
//Get Cost Unit Test
////////////////////

#include "dominion.h"
#include <stdio.h>

int failed = 0;

int myassert(int b,char* msg) {
  if (b == 0) {
    printf("getCost Test Failure: %s\n",msg);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("getCost Test Successful\n");
  }
}

void main()
{
	int cardNumber;
	int r;
	int I_want_to_be_a_card_too = 52;

	cardNumber = curse;
	r = getCost(cardNumber);
	myassert(r == 0, "curse, should return valid 0");
	
	cardNumber = estate;
	r = getCost(cardNumber);
	myassert(r == 2, "estate, should return valid 2");
	
	cardNumber = duchy;
	r = getCost(cardNumber);
	myassert(r == 5, "duchy, should return valid 5");
	
	cardNumber = province;
	r = getCost(cardNumber);
	myassert(r == 8, "province, should return valid 8");
	
	cardNumber = copper;
	r = getCost(cardNumber);
	myassert(r == 0, "copper, should return valid 0");
	
	cardNumber = silver;
	r = getCost(cardNumber);
	myassert(r == 3, "silver, should return valid 3");
	
	cardNumber = gold;
	r = getCost(cardNumber);
	myassert(r == 6, "gold, should return valid 6");
	
	cardNumber = adventurer;
	r = getCost(cardNumber);
	myassert(r == 6, "adventurer, should return valid 6");
	
	cardNumber = council_room;
	r = getCost(cardNumber);
	myassert(r == 5, "council_room, should return valid 5");
	
	cardNumber = feast;
	r = getCost(cardNumber);
	myassert(r == 4, "feast, should return valid 4");
	
	cardNumber = gardens;
	r = getCost(cardNumber);
	myassert(r == 4, "gardens, should return valid 4");
	
	cardNumber = mine;
	r = getCost(cardNumber);
	myassert(r == 5, "mine, should return valid 5");
	
	cardNumber = remodel;
	r = getCost(cardNumber);
	myassert(r == 4, "remodel, should return valid 4");

	cardNumber = smithy;
	r = getCost(cardNumber);
	myassert(r == 4, "smithy, should return valid 4");
	
	cardNumber = village;
	r = getCost(cardNumber);
	myassert(r == 3, "village, should return valid 3");
	
	cardNumber = baron;
	r = getCost(cardNumber);
	myassert(r == 4, "baron, should return valid 4");
	
	cardNumber = great_hall;
	r = getCost(cardNumber);
	myassert(r == 3, "great_hall, should return valid 3");
	
	cardNumber = minion;
	r = getCost(cardNumber);
	myassert(r == 5, "minion, should return valid 5");
	
	cardNumber = steward;
	r = getCost(cardNumber);
	myassert(r == 3, "steward, should return valid 3");

	cardNumber = tribute;
	r = getCost(cardNumber);
	myassert(r == 5, "tribute, should return valid 5");
	
	cardNumber = ambassador;
	r = getCost(cardNumber);
	myassert(r == 3, "ambassador, should return valid 3");
	
	cardNumber = cutpurse;
	r = getCost(cardNumber);
	myassert(r == 4, "cutpurse, should return valid 4");
	
	cardNumber = embargo;
	r = getCost(cardNumber);
	myassert(r == 2, "embargo, should return valid 2");
	
	cardNumber = outpost;
	r = getCost(cardNumber);
	myassert(r == 5, "outpost, should return valid 5");
	
	cardNumber = salvager;
	r = getCost(cardNumber);
	myassert(r == 4, "salvager, should return valid 4");

	cardNumber = sea_hag;
	r = getCost(cardNumber);
	myassert(r == 4, "sea_hag, should return valid 4");
	
	cardNumber = treasure_map;
	r = getCost(cardNumber);
	myassert(r == 4, "treasure_map, should return valid 4");
	
	cardNumber = I_want_to_be_a_card_too;
	r = getCost(cardNumber);
	myassert(r == -1, "I_want_to_be_a_card_too, should return invalid -1");
	
	checkasserts();
}