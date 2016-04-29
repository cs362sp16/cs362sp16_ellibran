CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)
	
unittestresults.out: rngs.o dominion.o interface.o unittest1 unittest2 unittest3
	

unittest1:
	gcc -o unittest1.o unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest1.o > tmp
	echo "Unit Test: 1" >> unittestresults.out
	echo "------------" >> unittestresults.out
	gcov dominion.c > unittestresults.out

unittest2:
	gcc -o unittest2.o unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest2.o > tmp
	echo "Unit Test: 2" >> unittestresults.out
	echo "------------" >> unittestresults.out
	gcov dominion.c > unittestresults.out

unittest3:
	gcc -o unittest3.o unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)
	./unittest3.o > tmp
	echo "Unit Test: 3" >> unittestresults.out
	echo "------------" >> unittestresults.out
	gcov dominion.c > unittestresults.out
	
all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
