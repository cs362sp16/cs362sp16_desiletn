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

assert.o: $(unittests/assert.h) $(unittests/assert.c)
	gcc -c unittests/assert.c -g $(CFLAGS)

unittests: $(unittests/unittest*.c) assert.o dominion.o
	gcc -o unittest1 unittests/unittest1.c -g assert.o dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 unittests/unittest2.c -g assert.o dominion.o rngs.o $(CFLAGS)

all: playdom player unittests

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittests/unittest1 unittests/unittest2 unittests/unittest3 unittests/unittest4 unittests/*.o cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
