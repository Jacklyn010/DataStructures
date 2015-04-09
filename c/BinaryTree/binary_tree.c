#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void binary_tree_add(Node *parent, int dir, int val) {
	Node *newNode;
	
	newNode = binary_tree_new_node(parent, val);
	
	if (dir == LEFT) {
		if (parent->left) {
			parent->left->parent = newNode;
			newNode->left = parent->left;
		}
		
		parent->left = newNode;
	} else if (dir == RIGHT) {
		if (parent->right) {
			parent->right->parent = newNode;
			newNode->right = parent->right;
		}
		
		parent->right = newNode;
	}
}

Node *binary_tree_new_node(Node *parent, int val) {
	Node *newNode;
	
	newNode = (Node *) malloc(sizeof(Node));
	
	newNode->parent = parent;
	newNode->val = val;
	
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

void binary_tree_delete_all(Node* root) {
	if (root->left) binary_tree_delete_all(root->left);
	if (root->right) binary_tree_delete_all(root->right);
	
	free(root);
}

/* Thanks to Wikipedia. */
boolean binary_tree_is_search_tree(Node *node, int min, int max) {
	if (!node) return TRUE;
	
	if (node->val < min) return FALSE;
	if (node->val > max) return FALSE;
	
	return binary_tree_is_search_tree(node->left, min, node->val) && 
		binary_tree_is_search_tree(node->right, node->val, max);
}

void binary_tree_depth_traversal(Node *node, Order ord) {
	if (!node) return;
	
	if (ord == PREORDER) printf("%d\n", node->val);
	binary_tree_depth_traversal(node->left, ord);
	if (ord == INORDER) printf("%d\n", node->val);
	binary_tree_depth_traversal(node->right, ord);
	if (ord == POSTORDER) printf("%d\n", node->val);
}


