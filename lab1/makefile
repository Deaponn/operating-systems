sources = countdown
CC = gcc
CFLAGS = -Wall

.PHONY: all
all :
	make countdown

.PHONY: debug
debug :
	make countdown-debug.out

countdown : countdown.c
	$(CC) countdown.c $(CFLAGS) -o countdown

countdown-debug.out : countdown.c
	$(CC) -g countdown.c $(CFLAGS) -o countdown-debug.out

.PHONY: clean
clean :
	rm $(sources) *-debug.out

test :
	echo $(GCC)