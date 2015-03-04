#include "stack.h"

using namespace std;

void Stack::push(const ListType &val) {
	Node *newNode = new Node(val);
	
	newNode->next = head;
	head = newNode;
	
	length++;
}

ListType Stack::pop() {
	Node *node = head;
	
	if (node == NULL) {
		// Stack is empty.
		cerr << "Stack::pop: Stack is empty." << endl;
		return (ListType) NULL;
	}
	
	int val = node->val;
	
	head = node->next;
	
	delete[] node;
	
	length--;
	
	return val;
}

ListType Stack::peek() {
	if (head == NULL) {
		// Stack is empty.
		cerr << "Stack::peek: Stack is empty." << endl;
		return (ListType) NULL;
	}
	
	return head->val;
}
