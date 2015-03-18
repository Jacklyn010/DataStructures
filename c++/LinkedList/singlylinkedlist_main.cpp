#include "singlylinkedlist.h"

using namespace std;

void printList(const LinkedList &list);

int main(void) {
	LinkedList list;
	
	list.add(5);
	list.add(10);
	list.add(25);
	list.add(955);
	list.add(1337);
	
	list.remove(4);
	
	list.add(2, 50);
	list.add(1, 12);
	
	printList(list);
	
	cout << "Get Index 2: " << list.get(2) << endl;
	
	cout << "Remove Index 4: " << list.remove(4) << endl;
	cout << "Remove Index 0: " << list.remove(0) << endl;
	
	printList(list);
	
	return 0;
}

void printList(const LinkedList &list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}
}
