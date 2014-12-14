CC		= gcc
CFLAGS	= -g -Wall -Wstrict-prototypes -ansi -pedantic

all: binary

binary: binary_tree.o binary_tree_tester.o
	$(CC) $(CFLAGS) binary_tree.o binary_tree_tester.o -o binary_tree_tester

binary_tree_tester.o: binary_tree.o binary_tree_tester.c
	$(CC) $(CFLAGS) -c binary_tree_tester.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c binary_tree.c

test: binary
	./binary_tree_tester

clean:
	rm -f *.o binary_tree_tester

