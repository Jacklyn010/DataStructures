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

#include "singlylinkedlist.cpp"

#endif
