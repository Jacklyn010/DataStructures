#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	LinkedList *list;
	Node *cur;
	
	list = (LinkedList*) calloc(1, sizeof(LinkedList));
	
	linked_list_add(list, 5);
	linked_list_add(list, 10);
	linked_list_add(list, 25);
	linked_list_add(list, 955);
	linked_list_add(list, 1337);
	
	for (cur = list->head; cur != NULL; cur = cur->next) {
		printf("%d", cur->val);
		
		if (cur->prev != NULL) {
			printf(" (prev: %d)", cur->prev->val);
		}
		
		printf("\n");
	}
	
	printf("Get Index 2: %d\n", linked_list_get(list, 2));
	printf("Remove Index 4: %d\n", linked_list_remove(list, 4));
	
	for (cur = list->head; cur != NULL; cur = cur->next) {
		printf("%d", cur->val);
		
		if (cur->prev) {
			printf(" (prev: %d)", cur->prev->val);
		}
		
		printf("\n");
	}
	
	free(list);
	
	return 0;
}
