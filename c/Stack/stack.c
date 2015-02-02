#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void stack_push(Stack *stack, int val) {
	Node *newNode;
	
	newNode = node_new(val);
	
	newNode->next = stack->head;
	stack->head = newNode;
}

int stack_pop(Stack *stack) {
	Node *popped;
	int val;
	
	if (!stack) {
		fprintf(stderr, "Stack is null\n");
		return -1;
	}
	
	popped = stack->head;
	stack->head = popped->next;
	val = popped->val;
	
	free(popped);
	
	return val;
}

int stack_peek(Stack *stack) {
	if (!stack->head) {
		fprintf(stderr, "Stack is empty\n");
		return -1;
	}
	
	return stack->head->val;
}
