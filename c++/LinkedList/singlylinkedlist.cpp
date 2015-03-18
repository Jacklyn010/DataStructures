#include "singlylinkedlist.h"

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	length = 0;
}

LinkedList::~LinkedList() {
	destroyList(head);
}

void LinkedList::destroyList(Node *node) {
	if (node->next == NULL) {
		delete[] node;
		return;
	}
	
	destroyList(node->next);
}

void LinkedList::add(const ListType &val) {
	add(length, val);
}

void LinkedList::add(int index, const ListType &val) {
	Node *node = newNode(val);
	
	if (index == 0) {
		// Head insertion. 
		
		// Set the current head as the node's next.
		node->next = head;
		
		// Then set the current head to node.
		head = node;
		
		if (length == 0) {
			tail = node;
		}
	} else if (index == length) {
		// Tail insertion.
		
		if (tail != NULL) {
			// Set tail's next.
			tail->next = node;
		}
		
		// Set current tail to node.
		tail = node;
	} else {
		Node *cur = head;
		for (int i = 0; 
			cur->next != NULL && i < index - 1; 
			cur = cur->next, i++) {
			
		}
		
		// Insert in the middle of array.
		node->next = cur->next;
		cur->next = node;
	}
	
	length++;
}

ListType LinkedList::get(int index) const {
	if (index >= length) {
		cerr << "LinkedList::get: Array index out of bounds." << endl;
		return (ListType) NULL;
	}
	
	Node *node = head;
	
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	
	return node->val;
}

ListType LinkedList::remove(int index) {
	Node *removed;
	ListType value;
	
	if (index < 0 || index > length - 1) {
		cerr << "LinkedList::remove: Array index out of bounds." << endl;
		return (ListType) NULL;
	}
	
	// If the head is what we want to delete, then do so accordingly.
	if (index == 0) {
		removed = head;
		
		head = head->next;
	} else {
		// If not, then we'll need to traverse through the list.
		Node *curNode = head;
		
		for (int i = 0; i < index - 1; i++) {
			curNode = curNode->next;
		}
		
		if (curNode->next == tail) {
			// Tail deletion
			tail = curNode;
		}
		
		removed = curNode->next;
	
		curNode->next = removed->next;
	}
	
	// Delete the node and decrement the number of items.
	value = removed->val;
	delete[] removed;
	
	length--;
	return value;
}

Node* LinkedList::newNode(const ListType &val) {
	Node *node = new Node(val);
	
	return node;
}
