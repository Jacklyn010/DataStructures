#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef int ListType;

struct Node {
	Node* prev;
	Node* next;
	ListType val;
	
	Node():prev(NULL), next(NULL) {}
	Node(const ListType &val):val(val) {}
};

class LinkedList {
public:
	LinkedList();
	//LinkedList(const LinkedList &other);
	~LinkedList();
	void add(const ListType &val);
	void add(int index, const ListType &val);
	
	ListType remove(int ind);
	
	ListType get(int ind);
	
	int size() { return length; }

private:
	void destroyList(Node *node);

	Node *newNode(const ListType &val);

	int length;
	Node *head;
	Node *tail;
};

#endif
