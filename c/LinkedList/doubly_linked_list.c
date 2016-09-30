/**
 * Doubly linked list
 */

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *linked_list_new(void) {
	return (LinkedList *) calloc(1, sizeof(LinkedList));
}

void linked_list_destroy(LinkedList *list) {
	Node *cur = list->head;
	Node *next = NULL;
	
	while (cur != NULL) {
		next = cur->next;
		free(cur);
		cur = next;
	}
	
	free(list);
}

Node *node_new(int val) {
	Node *newNode;
	
	newNode = (Node *) malloc(sizeof(Node));
	
	newNode->prev = NULL;
	newNode->next = NULL;
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
	
	list->tail = toAdd;
	
	list->elems++;
}

int linked_list_remove(LinkedList *list, size_t index) {
	Node *cur, *removedNode;
	int removedVal;
	size_t i;
	
	cur = list->head;
	
	for (i = 0; i < index - 1; i++) {
		if (!cur) {
			fprintf(stderr, "LinkedList index out of bounds: %lu\n", index);
			return -1;
		}
		
		cur = cur->next;
	}
	
	if (!cur->next) {
		fprintf(stderr, "LinkedList index out of bounds: %lu\n", index);
		return -1;
	}
	
	removedNode = cur->next;
	removedVal = cur->next->val;
	
	if (cur->next->next) {
		cur->next = cur->next->next;
		
		cur->next->prev = cur;
	} else {
		cur->next = NULL;
		list->tail = cur;
	}
	
	free(removedNode);
	
	return removedVal;
}

int linked_list_get(LinkedList *list, size_t index) {
	Node *cur;
	size_t i;
	
	cur = list->head;
	
	for (i = 0; i < index; i++) {
		if (!cur) {
			fprintf(stderr, "LinkedList index out of bounds: %lu", index);
			return -1;
		}
		
		cur = cur->next;
	}
	
	return cur->val;
}
