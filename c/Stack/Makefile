CC		= gcc
CFLAGS	= -I.. -g -Wall -Wstrict-prototypes -ansi -pedantic

all: stack

stack: stack.o stack_tester.o
	$(CC) $(CFLAGS) ../LinkedList/singly_linked_list.o stack.o stack_tester.o -o stack_tester

stack_tester.o: stack.o stack_tester.c
	$(CC) $(CFLAGS) -c stack_tester.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

test: stack
	./stack_tester

clean:
	rm -f *.o stack_tester

