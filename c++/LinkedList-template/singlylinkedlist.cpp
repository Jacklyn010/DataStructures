#include "singlylinkedlist.h"

using namespace std;

template <typename T>
void LinkedList<T>::add(const T &val) {
	Node<T> *node = newNode(val);
	
	if (!head) {
		head = node;
	} else {
		tail->next = node;
	}
	
	tail = node;
	
	length++;
}

template <typename T>
T LinkedList<T>::get(int index) {
	if (index >= length) {
		std::cerr << "LinkedList::get: Array index out of bounds." << std::endl;
		return 0;
	}
	
	Node<T> *node = head;
	
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	
	return node->val;
}

template <typename T>
T LinkedList<T>::remove(int index) {
	return 0;
}

template <typename T>
Node<T>* LinkedList<T>::newNode(const T &val) {
	Node<T> *node = new Node<T>;
	
	node->val = val;
	node->next = NULL;
	
	return node;
}
