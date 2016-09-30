#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	LinkedList *list;
	Node *cur;
	
	list = linked_list_new();
	
	linked_list_add(list, 1);
	linked_list_add(list, 2);
	linked_list_add(list, 3);
	linked_list_add(list, 4);
	linked_list_add(list, 5);
	
	printf("Tail: %d\n", list->tail->val);
	
	for (cur = list->head; cur != NULL; cur = cur->next) {
		printf("%d\n", cur->val);
	}
	
	printf("Get Index 2: %d\n", linked_list_get(list, 2));
	printf("Remove Index 4: %d\n", linked_list_remove(list, 4));
	printf("Remove Index 0: %d\n", linked_list_remove(list, 0));
	
	for (cur = list->head; cur != NULL; cur = cur->next) {
		printf("%d\n", cur->val);
	}
	
	printf("Tail: %d\n", list->tail->val);
	
	linked_list_destroy(list);
	
	return 0;
}
