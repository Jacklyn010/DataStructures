#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Stack *stack;
	
	stack = (Stack *) malloc(sizeof(Stack));
	
	stack_push(stack, 5);
	stack_push(stack, 4);
	stack_push(stack, 3);
	stack_push(stack, 2);
	stack_push(stack, 1);
	stack_push(stack, 0);
	
	printf("Peek: %d\n", stack_peek(stack));
	
	while (stack->head) {
		printf("%d\n", stack_pop(stack));
	}
	
	return 0;
}
