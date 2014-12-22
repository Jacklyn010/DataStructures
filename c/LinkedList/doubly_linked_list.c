/**
 * Doubly linked list
 */

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *node_new(int val) {
	Node *newNode;
	
	newNode = (Node *) malloc(sizeof(Node));
	
	newNode->val = val;
	
	return newNode;
}

void linked_list_add(LinkedList *list, int val) {
	Node *cur;
	Node *toAdd;
	
	toAdd = node_new(val);
	
	if (!list->head) {
		list->head = toAdd;
	} else {
		cur = list->head;
		
		while (cur->next) {
			cur = cur->next;
		}
		
		cur->next = toAdd;
		toAdd->prev = cur;
	}
	
	list->elems++;
}

int linked_list_remove(LinkedList *list, int index) {
	Node *cur;
	int removed;
	int i;
	
	cur = list->head;
	
	for (i = 0; i < index - 1; i++) {
		if (!cur) {
			fprintf(stderr, "LinkedList index out of bounds: %d\n", index);
			return -1;
		}
		
		cur = cur->next;
	}
	
	if (!cur->next) {
		fprintf(stderr, "LinkedList index out of bounds: %d\n", index);
		return -1;
	}
	
	removed = cur->next->val;
	
	free(cur->next);
	
	if (cur->next->next) {
		cur->next = cur->next->next;
		
		cur->next->prev = cur;
	} else {
		cur->next = NULL;
	}
	
	return removed;
}

int linked_list_get(LinkedList *list, int index) {
	Node *cur;
	int i;
	
	cur = list->head;
	
	for (i = 0; i < index; i++) {
		if (!cur) {
			fprintf(stderr, "LinkedList index out of bounds: %d", index);
			return -1;
		}
		
		cur = cur->next;
	}
	
	return cur->val;
}
