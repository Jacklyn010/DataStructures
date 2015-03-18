# Based off of my Makefiles in the CaltechCS11 repo.

CC		= g++
CFLAGS	= -g -Wall -ansi -pedantic

all: singly

singly: singlylinkedlist.h singlylinkedlist_main.o
	$(CC) $(CFLAGS) singlylinkedlist.h singlylinkedlist_main.o -o singlylinkedlist_main

singlylinkedlist_main.o: singlylinkedlist_main.cpp
	$(CC) $(CFLAGS) -c singlylinkedlist_main.cpp

singlylinkedlist.o: singlylinkedlist.h
	$(CC) $(CFLAGS) -c singlylinkedlist.h

test: singly
	./singlylinkedlist_main

clean:
	rm -f *.o singlylinkedlist_main doublylinkedlist_main

