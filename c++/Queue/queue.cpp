#include "queue.h"
#include <iostream>

using namespace std;

void Queue::enqueue(const ListType &val) {
	list.add(val);
}

ListType Queue::dequeue() {
	if (isEmpty()) {
		cerr << "Queue is empty" << endl;
		return (ListType) NULL;
	}
	
	return list.remove(0);
}

ListType Queue::peek() const {
	if (isEmpty()) {
		cerr << "Queue is empty" << endl;
		return (ListType) NULL;
	}
	
	return list.get(0);
}
