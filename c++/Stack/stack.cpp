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
	int val = node->val;
	
	head = node->next;
	
	delete[] node;
	
	length--;
	
	return val;
}

ListType Stack::peek() {
	return head->val;
}
