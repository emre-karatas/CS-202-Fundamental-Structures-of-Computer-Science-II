CC=g++

CFLAGS=-c -Wall

all: hw

hw: main.o sorting.o
	$(CC) main.o sorting.o -o hw1


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



sorting.o: sorting.cpp
	$(CC) $(CFLAGS) sorting.cpp


clean:
	rm *o hw1
