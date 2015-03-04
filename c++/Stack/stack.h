#include "LinkedList/singlylinkedlist.h"

#ifndef STACK_H
#define STACK_H

class Stack {
public:
	Stack():head(NULL), length(0) {}
	
	void push(ListType val);
	ListType pop();
	ListType peek();
	
	bool hasNext() { return length > 0; }

private:
	Node *head;
	int length;
};

#endif
