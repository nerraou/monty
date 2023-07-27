#include "monty.h"

/**
 * pop_dlistnode - pop dlistnode
 * @stack: stack
 */
void pop_dlistnode(stack_t **stack)
{
	stack_t *node;

	node = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(node);
}
