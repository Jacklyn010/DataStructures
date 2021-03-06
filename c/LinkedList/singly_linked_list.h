#include <stddef.h>

typedef struct Node Node;

struct Node {
	Node *next;
	int val;
};

typedef struct LinkedList {
	size_t elems;
	Node *head;
	Node *tail;
} LinkedList;

LinkedList *linked_list_new(void);
void linked_list_destroy(LinkedList *list);

Node *node_new(int val);
void linked_list_add(LinkedList *list, int val);
int linked_list_remove(LinkedList *list, size_t index);
int linked_list_get(LinkedList *list, size_t index);
