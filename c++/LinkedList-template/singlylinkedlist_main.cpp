#include "singlylinkedlist.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main(void) {
	LinkedList<int> list;
	LinkedList<const char*> stringList;
	
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	
	stringList.add("hello");
	stringList.add("world");
	stringList.add("banana");
	
	cout << "Test 1: List size" << endl;
	
	assert(list.size() == 5);
	assert(stringList.size() == 3);
	
	cout << "Test 2: Data retrieval" << endl;
	
	assert(list.get(2) == 3);
	assert(strcmp(stringList.get(2), "banana") == 0);
	
	cout << "Test 3: Data removal" << endl;
	
	assert(list.remove(3) == 4);
	
	cout << "Test 4: Copy constructor" << endl;
	
	LinkedList<int> listTwo(list);
	assert(listTwo.size() == list.size());
	
	cout << "All tests passed!" << endl;
	
	return 0;
}
