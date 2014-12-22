#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Queue *queue;
	int i;
	
	queue = (Queue *) malloc(sizeof(Queue));
	
	queue_enqueue(queue, 0);
	queue_enqueue(queue, 1);
	queue_enqueue(queue, 2);
	queue_enqueue(queue, 3);
	queue_enqueue(queue, 4);
	queue_enqueue(queue, 5);
	
	printf("Peek: %d\n", queue_peek(queue));
	
	while (queue->head) {
		printf("%d\n", queue_dequeue(queue));
	}
	
	return 0;
}
