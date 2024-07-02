sources = zad1 zad2
CC = gcc
CFLAGS = -Wall

.PHONY: all
all :
	make zad1
	make zad2

# .PHONY: run
# run :
# 	make flipper
# 	./flipper ./art ./output

zad1 : zad1.c
	$(CC) zad1.c $(CFLAGS) -o zad1

zad2 : zad2.c
	$(CC) zad2.c $(CFLAGS) -o zad2

.PHONY: clean
clean :
	rm $(sources)
