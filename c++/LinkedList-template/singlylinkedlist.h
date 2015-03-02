#include <cstdlib>
#include <iostream>

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

template <typename T>
struct Node {
	Node<T> *next;
	T val;
};

template <typename T>
class LinkedList {
public:
	LinkedList() {}
	//LinkedList(const LinkedList &other);
	//~LinkedList();
	void add(T val);
	
	T remove(int ind);
	
	T get(int ind);
	
	int size() { return length; }

private:
	Node<T> *newNode(T val);

	int length;
	Node<T> *head;
	Node<T> *tail;
};

template <typename T>
void LinkedList<T>::add(T val) {
	Node<T> *node = newNode(val);
	
	if (!head) {
		head = node;
	}
	
	if (tail) {
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
	
	for (int i = 0; i <= index; i++) {
		node = node->next;
	}
	
	return node->val;
}

template <typename T>
T LinkedList<T>::remove(int index) {
	return 0;
}

template <typename T>
Node<T>* LinkedList<T>::newNode(T val) {
	Node<T> *node = new Node<T>;
	
	node->val = val;
	
	return node;
}

#endif
