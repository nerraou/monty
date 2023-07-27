#include "monty.h"

/**
 * _op_swap - pop node
 * @stack: list head
 * @l_num: line number
 */

void _op_swap(stack_t **stack, unsigned int l_num)
{
	int stack_size;
	int tmp;

	stack_size = dlistint_len(*stack);
	if (*stack == NULL || stack_size < 2)
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't swap, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
