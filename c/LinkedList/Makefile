# Based off of my Makefiles in the CaltechCS11 repo.

CC		= gcc
CFLAGS	= -g -Wall -Wstrict-prototypes -ansi -pedantic

all: singly

singly: singly_linked_list.o singly_linked_list_tester.o
	$(CC) $(CFLAGS) singly_linked_list.o singly_linked_list_tester.o -o singly_linked_list_tester

singly_linked_list_tester.o: singly_linked_list.o singly_linked_list_tester.c
	$(CC) $(CFLAGS) -c singly_linked_list_tester.c

singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	$(CC) $(CFLAGS) -c singly_linked_list.c

test: singly
	./singly_linked_list_tester

clean:
	rm -f *.o singly_linked_list_tester

