CC		= gcc
CFLAGS	= -g -Wall -Werror -Wstrict-prototypes -ansi -pedantic

all: singly doubly

singly: singly_linked_list.o singly_linked_list_tester.o
	$(CC) $(CFLAGS) singly_linked_list.o singly_linked_list_tester.o -o singly_linked_list_tester

singly_linked_list_tester.o: singly_linked_list.o singly_linked_list_tester.c
	$(CC) $(CFLAGS) -c singly_linked_list_tester.c

singly_linked_list.o: singly_linked_list.c singly_linked_list.h
	$(CC) $(CFLAGS) -c singly_linked_list.c

doubly: doubly_linked_list.o doubly_linked_list_tester.o
	$(CC) $(CFLAGS) doubly_linked_list.o doubly_linked_list_tester.o -o doubly_linked_list_tester

doubly_linked_list_tester.o: doubly_linked_list.o doubly_linked_list_tester.c
	$(CC) $(CFLAGS) -c doubly_linked_list_tester.c

doubly_linked_list.o: doubly_linked_list.c doubly_linked_list.h
	$(CC) $(CFLAGS) -c doubly_linked_list.c

test: singly doubly
	./singly_linked_list_tester
	./doubly_linked_list_tester

clean:
	rm -f *.o singly_linked_list_tester doubly_linked_list_tester

