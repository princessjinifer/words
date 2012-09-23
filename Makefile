# compiler to use:
CC=g++
# flags to use:
CFLAGS=-c -Wall

all: words

words: src/words.o src/ccalc.o
	$(CC) src/words.o src/ccalc.o -o bin/words

words.o: src/words.cpp
	$(CC) $(CFLAGS) src/words.cpp

ccalc.o: src/ccalc.cpp
	$(CC) $(CFLAGS) src/ccalc.cpp

clean:
	rm -rf src/*o
