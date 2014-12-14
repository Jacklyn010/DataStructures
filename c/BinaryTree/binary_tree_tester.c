#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Node *start;
	
	start = binary_tree_new_node(NULL, 0);
	
	binary_tree_add(start, LEFT, 1);
	binary_tree_add(start, RIGHT, 2);
	binary_tree_add(start->right, LEFT, 3);
	
	printf("%d\n", start->left->val);
	printf("%d\n", start->left->parent->val);
	printf("%d\n", start->right->left->val);
	printf("%d\n", start->right->left->parent->val);
	
	return 0;
}
