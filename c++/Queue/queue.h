#include "LinkedList/singlylinkedlist.h"

#ifndef QUEUE_H
#define QUEUE_H

static const int TOP_LOCATION = 0;

class Queue {
public:
	Queue() {}
	Queue(const Queue &other):list(other.list) {}
	~Queue() {}
	
	void enqueue(const ListType &val);
	ListType dequeue();
	ListType peek() const;
	
	int size() const { return list.size(); }
	bool hasNext() const { return list.size() > 0; }
	bool isEmpty() const { return list.size() == 0; }
	bool isFull() const { return false; }
private:
	LinkedList list;
};

#endif
