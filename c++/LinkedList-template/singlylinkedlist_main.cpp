#include "singlylinkedlist.h"
#include <iostream>

using namespace std;

int main(void) {
	LinkedList<int> list;
	
	list.add(5);
	list.add(10);
	list.add(25);
	list.add(955);
	list.add(1337);
	
	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}
	
	cout << "Get Index 2: " << list.get(2) << endl;
	//printf("Remove Index 4: %d\n", linked_list_remove(list, 4));
	//printf("Remove Index 0: %d\n", linked_list_remove(list, 0));
	
	return 0;
}
