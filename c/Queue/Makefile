CC		= gcc
CFLAGS	= -I.. -g -Wall -Wstrict-prototypes -ansi -pedantic

all: queue

queue: queue.o queue_tester.o
	$(CC) $(CFLAGS) ../LinkedList/singly_linked_list.o queue.o queue_tester.o -o queue_tester

queue_tester.o: queue.o queue_tester.c
	$(CC) $(CFLAGS) -c queue_tester.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

test: queue
	./queue_tester

clean:
	rm -f *.o queue_tester

