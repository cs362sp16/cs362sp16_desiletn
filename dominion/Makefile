CFLAGS = -std=c99 -Wall -fpic -coverage -lm

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

assert.o: $(tests/assert.h) $(tests/assert.c)
	gcc -c tests/assert.c -g $(CFLAGS)

tests: $(tests/unittest*.c) $(tests/cardtest*.c) assert.o dominion.o
	gcc -o unittest1 tests/unittest1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 tests/unittest2.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 tests/unittest3.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 tests/unittest4.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1 tests/cardtest1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 tests/cardtest2.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 tests/cardtest3.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 tests/cardtest4.c -g assert.o dominion.o rngs.o $(CFLAGS)

all: playdom player tests

clean:
	rm -f *.o playdom.exe playdom test.exe test player tests/unittest1 tests/unittest2 tests/unittest3 tests/unittest4 tests/*.o cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
