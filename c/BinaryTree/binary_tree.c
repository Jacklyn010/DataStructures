#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void binary_tree_add(Node *parent, int dir, int val) {
	Node *newNode;
	
	newNode = binary_tree_new_node(parent, val);
	
	if (dir == LEFT) {
		newNode->left = parent->left;
		parent->left = newNode;
	} else if (dir == RIGHT) {
		newNode->right = parent->right;
		parent->right = newNode;
	}
}

Node *binary_tree_new_node(Node *parent, int val) {
	Node *newNode;
	
	newNode = (Node *) malloc(sizeof(Node));
	
	newNode->parent = parent;
	newNode->val = val;
	
	return newNode;
}
