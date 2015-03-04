CC		= g++
CFLAGS	= -I.. -g -Wall -ansi -pedantic

all: stack

stack: stack.o stack_main.o
	$(CC) $(CFLAGS) ../LinkedList/singlylinkedlist.o stack.o stack_main.o -o stack_main

stack_main.o: stack.o stack_main.cpp
	$(CC) $(CFLAGS) -c stack_main.cpp

stack.o: stack.cpp stack.h
	$(CC) $(CFLAGS) -c stack.cpp

test: stack
	./stack_main

clean:
	rm -f *.o stack_main

