#!/bin/bash

CFLAGS = -std=c99 -Wall -fpic -coverage -lm
ANSWER_TO_LIFE = 42

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

unittestresults.out: $(tests/unittest*.c) $(tests/cardtest*.c) assert.o dominion.o
	gcc -o unittest1 tests/unittest1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 tests/unittest2.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 tests/unittest3.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 tests/unittest4.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest1 tests/cardtest1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 tests/cardtest2.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 tests/cardtest3.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 tests/cardtest4.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard1 tests/randomtestcard1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestcard2 tests/randomtestcard2.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o randomtestadventurer tests/randomtestadventurer.c -g assert.o dominion.o rngs.o $(CFLAGS)

	rm -f unittestresults.out
	rm -f randomtestcard1.out
	rm -f randomtestcard2.out
	rm -f randomtestadventurer.out

	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./randomtestcard1 $(ANSWER_TO_LIFE) >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./randomtestcard2 $(ANSWER_TO_LIFE) >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	./randomtestadventurer $(ANSWER_TO_LIFE) >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

testdominion: $(tests/testdominion.c) dominion.o
	gcc -o testdominion tests/testdominion.c -g dominion.o rngs.o $(CFLAGS)

test: playdom player testdominion

all: playdom player testdominion unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player tests/unittest1 tests/unittest2 tests/unittest3 tests/unittest4 tests/*.o cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM unittesting.out
