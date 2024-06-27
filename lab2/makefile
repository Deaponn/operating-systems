sources = client
CC = gcc
CFLAGS = -Wall -O0

.PHONY: all
all :
	make collatz.a
	make collatz.so
	make client

collatz.o : collatz.c
	$(CC) -c collatz.c

# compile static library
libcollatz.a : collatz.c
	$(CC) -c collatz.c
	ar -rcs libcollatz.a collatz.o
	rm collatz.o

# compile shared library
libcollatz.so : collatz.c
	$(CC) -fPIC -c collatz.c
	$(CC) -shared collatz.o -o libcollatz.so
	rm collatz.o

# using static library
client-static : client.c libcollatz.a
	$(CC) $(CFLAGS) client.c libcollatz.a -o client-static
	# $(CC) $(CFLAGS) client.c -L. -l collatz -o client-static

# using shared library
client-shared : client.c libcollatz.so
	$(CC) $(CFLAGS) client.c -L. -lcollatz -Wl,-rpath,. -o client-shared

# gdyby nie uzywac flag -Wl,-rpath,. w powyzszej komendzie
# export LD_LIBRARY_PATH=/home/bartosz/College/semester_4/operating-systems/lab2:$LD_LIBRARY_PATH

# using dynamic library
client-dynamic : client.c libcollatz.so
	$(CC) $(CFLAGS) client.c -D DYNAMIC=1 -o client-dynamic

.PHONY: clean
clean :
	rm $(sources) ./client-* ./lib* ./*.o
