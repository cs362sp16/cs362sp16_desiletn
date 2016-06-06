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

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom test.exe test player tests/unittest1 tests/unittest2 tests/unittest3 tests/unittest4 tests/*.o cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM unittesting.out
