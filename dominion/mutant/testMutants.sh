#!/bin/bash

i=100001
max=102539

# Backup original dominion.c file
mv dominion.c dominion.c.backup

for (($i; $i <= $max; i=i+1))
do
	target_dom="mutant${i}_dominion.c"
	cp $target_dom "${target_dom}.tmp"
	mv $target_dom dominion.c
	make -f Makefile unittestresults.out
	mv "${target_dom}.tmp" $target_dom
	make -f Makefile clean
done

mv dominion.c.backup dominion.c
