#include "monty.h"

/**
 * _op_push - add node
 * @stack: list head
 * @n: value
 */
void _op_push(stack_t **stack, unsigned int n)
{
	if (add_dnodeint(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}
