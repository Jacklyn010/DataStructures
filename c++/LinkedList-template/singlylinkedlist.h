#include <cstdlib>
#include <iostream>

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

enum LinkedListError {
	ARRAY_INDEX_OUT_OF_BOUNDS
};

class LinkedListException {
public:
	LinkedListException(LinkedListError e):err(e) {}
	LinkedListError getException() { return err; }
private:
	LinkedListError err;
};

template <typename T>
struct Node {
	Node<T> *next;
	T val;
};

template <typename T>
class LinkedList {
public:
	LinkedList():head(NULL), tail(NULL), length(0) {}
	//LinkedList(const LinkedList &other);
	~LinkedList();
	void add(const T &val);
	
	T remove(int ind);
	
	T get(int ind);
	
	int size() const { return length; }

private:
	Node<T> *newNode(const T &val);
	Node<T> *getNode(int ind);
	
	Node<T> *head;
	Node<T> *tail;

	int length;
};

#include "singlylinkedlist.cpp"

#endif
