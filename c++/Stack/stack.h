#include "LinkedList/singlylinkedlist.h"

#ifndef STACK_H
#define STACK_H

static const int TOP_LOCATION = 0;

class Stack {
public:
	Stack() {}
	Stack(const Stack &other):list(other.list) {}
	~Stack() {}
	
	void push(const ListType &val);
	ListType pop();
	ListType peek() const;
	
	int size() const { return list.size(); }
	bool hasNext() const { return list.size() > 0; }
	bool isEmpty() const { return list.size() == 0; }
	bool isFull() const { return false; }
private:
	LinkedList list;
};

#endif
