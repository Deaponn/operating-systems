sources = flipper
CC = gcc
CFLAGS = -Wall

.PHONY: all
all :
	make flipper

.PHONY: run
run :
	make flipper
	./flipper ./art ./output

flipper : flipper.c
	$(CC) flipper.c $(CFLAGS) -o flipper

.PHONY: clean
clean :
	-rm $(sources) ./output/*
	rmdir ./output
