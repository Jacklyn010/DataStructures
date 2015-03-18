#include "stack.h"

using namespace std;

void Stack::push(const ListType &val) {
	list.add(TOP_LOCATION, val);
}

ListType Stack::pop() {
	if (isEmpty()) {
		// Stack is empty.
		cerr << "Stack::pop: Stack is empty." << endl;
		return (ListType) NULL;
	}
	
	return list.remove(TOP_LOCATION);
}

ListType Stack::peek() const {
	if (isEmpty()) {
		// Stack is empty.
		cerr << "Stack::peek: Stack is empty." << endl;
		return (ListType) NULL;
	}
	
	return list.get(TOP_LOCATION);
}
