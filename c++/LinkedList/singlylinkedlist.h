#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

typedef int ListType;

struct Node {
	Node* next;
	ListType val;
	
	Node():next(NULL) {}
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
	
	ListType get(int ind) const;
	
	int size() const { return length; }

private:
	void destroyList(Node *node);

	Node *newNode(const ListType &val);

	int length;
	Node *head;
	Node *tail;
};

#endif
