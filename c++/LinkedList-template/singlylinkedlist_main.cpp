#include "singlylinkedlist.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(void) {
	LinkedList<int> list;
	LinkedList<const char*> stringList;
	
	list.add(5);
	list.add(10);
	list.add(25);
	list.add(955);
	list.add(1337);
	
	stringList.add("hello");
	
	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}

	assert(stringList.get(0) == "hello");
	assert(list.get(2) == 25);
	assert(list.remove(3) == 955);
	
	cout << "Get Index 2: " << list.get(2) << endl;

	cout << stringList.get(0) << endl;
	
	return 0;
}
