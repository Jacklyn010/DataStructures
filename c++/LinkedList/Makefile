# Based off of my Makefiles in the CaltechCS11 repo.

CC		= g++
CFLAGS	= -g -Wall -ansi -pedantic

all: singly doubly

singly: singlylinkedlist.o singlylinkedlist_main.o
	$(CC) $(CFLAGS) singlylinkedlist.o singlylinkedlist_main.o -o singlylinkedlist_main

singlylinkedlist_main.o: singlylinkedlist.o singlylinkedlist_main.cpp
	$(CC) $(CFLAGS) -c singlylinkedlist_main.cpp

singlylinkedlist.o: singlylinkedlist.cpp singlylinkedlist.h
	$(CC) $(CFLAGS) -c singlylinkedlist.cpp

doubly: doublylinkedlist.o doublylinkedlist_main.o
	$(CC) $(CFLAGS) doublylinkedlist.o doublylinkedlist_main.o -o doublylinkedlist_main

doublylinkedlist_main.o: doublylinkedlist.o doublylinkedlist_main.cpp
	$(CC) $(CFLAGS) -c doublylinkedlist_main.cpp

doublylinkedlist.o: doublylinkedlist.cpp doublylinkedlist.h
	$(CC) $(CFLAGS) -c doublylinkedlist.cpp

test: singly doubly
	./singlylinkedlist_main
	./doublylinkedlist_main

clean:
	rm -f *.o singlylinkedlist_main doublylinkedlist_main

