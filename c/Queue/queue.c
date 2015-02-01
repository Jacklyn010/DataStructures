#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_enqueue(Queue *queue, int val) {
	if (!queue) {
		fprintf(stderr, "Queue is null\n");
		return;
	}
	
	linked_list_add(queue, val);
}

int queue_dequeue(Queue *queue) {
	if (!queue) {
		fprintf(stderr, "Queue is null\n");
		return;
	}
	
	if (!queue->head) {
		fprintf(stderr, "Queue is empty\n");
		return -1;
	}
	
	return linked_list_remove(queue, 0);
}

int queue_peek(Queue *queue) {
	if (!queue) {
		fprintf(stderr, "Queue is null\n");
		return;
	}
	
	if (!queue->head) {
		fprintf(stderr, "Queue is empty\n");
		return -1;
	}
	
	return linked_list_get(queue, 0);
}
