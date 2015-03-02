#include "doublylinkedlist.h"

using namespace std;

int main(void) {
	LinkedList list;
	
	list.add(5);
	list.add(10);
	list.add(25);
	list.add(955);
	list.add(1337);
	
	list.add(2, 50);
	list.add(1, 12);
	
	for (int i = 0; i < list.size(); i++) {
		cout << list.get(i) << endl;
	}
	
	cout << "Get Index 2: " << list.get(2) << endl;
	
	//printf("Remove Index 4: %d\n", linked_list_remove(list, 4));
	//printf("Remove Index 0: %d\n", linked_list_remove(list, 0));
	
	/*Node *ptr = list.head;
	
	while (ptr) {
		cout << ptr << " => " << ptr->prev << ", " << ptr->val << ", " << ptr->next << endl;
		
		ptr = ptr->next;
	}*/
	
	return 0;
}
