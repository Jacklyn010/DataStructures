#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void binary_tree_test_normal(void);
void binary_tree_test_search_tree_1(void);
void binary_tree_test_search_tree_2(void);

void binary_tree_test_normal(void) {
	Node *start;
	
	start = binary_tree_new_node(NULL, 0);
	
	binary_tree_add(start, LEFT, 1);
	binary_tree_add(start, RIGHT, 2);
	binary_tree_add(start->right, LEFT, 3);
	binary_tree_add(start, RIGHT, 5);
	
	/* Expected output: 1 0 2 5 */
	printf("%d\n", start->left->val);
	printf("%d\n", start->left->parent->val);
	printf("%d\n", start->right->right->val);
	printf("%d\n", start->right->right->parent->val);
	
	binary_tree_delete_all(start);
}

void binary_tree_test_search_tree_1(void) {
	Node *start;
	
	start = binary_tree_new_node(NULL, 8);
	
	binary_tree_add(start, LEFT, 3);
	binary_tree_add(start->left, LEFT, 1);
	binary_tree_add(start->left, RIGHT, 6);
	binary_tree_add(start->left->right, LEFT, 4);
	binary_tree_add(start->left->right, RIGHT, 7);
	
	binary_tree_add(start, RIGHT, 10);
	binary_tree_add(start->right, RIGHT, 14);
	binary_tree_add(start->right->right, LEFT, 13);
	
	printf("%s\n", binary_tree_is_search_tree(start, 0, 100) 
		? "true" : "false");
	
	binary_tree_delete_all(start);
}

void binary_tree_test_search_tree_2(void) {
	Node *start;
	
	start = binary_tree_new_node(NULL, 20);
	
	binary_tree_add(start, LEFT, 10);
	
	binary_tree_add(start, RIGHT, 30);
	binary_tree_add(start->right, RIGHT, 40);
	binary_tree_add(start->right, LEFT, 5);
	
	printf("%s\n", binary_tree_is_search_tree(start, 1, 100) 
		? "true" : "false");
	
	binary_tree_delete_all(start);
}

int main(void) {
	binary_tree_test_search_tree_1();
	
	return 0;
}
