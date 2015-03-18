CC		= g++
CFLAGS	= -I.. -g -Wall -ansi -pedantic

all: queue

queue: queue.o queue_main.o
	$(CC) $(CFLAGS) ../LinkedList/singlylinkedlist.o queue.o queue_main.o -o queue_main

queue_main.o: queue.o queue_main.cpp
	$(CC) $(CFLAGS) -c queue_main.cpp

queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) -c queue.cpp

test: queue
	./queue_main

clean:
	rm -f *.o queue_main

