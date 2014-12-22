/**
 * Singly linked list
 */

#include "singly_linked_list.h"
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
	}
	
	list->tail = toAdd;
	
	list->elems++;
}

int linked_list_remove(LinkedList *list, int index) {
	Node *cur, *toRemove;
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
	
	if (index > 0) {
		if (!cur->next) {
			fprintf(stderr, "LinkedList index out of bounds: %d\n", index);
			return -1;
		}
		
		toRemove = cur->next;
		removed = toRemove->val;
	
		if (toRemove->next) {
			cur->next = toRemove->next;
		} else {
			cur->next = NULL;
			list->tail = cur;
		}
		
		free(toRemove);
	} else {
		toRemove = cur;
		removed = toRemove->val;
		
		list->head = toRemove->next;
		
		free(toRemove);
	}
	
	list->elems--;
	
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
