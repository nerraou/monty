#include "monty.h"

/**
 * _op_sub - sub node
 * @stack: list head
 * @l_num: line number
 */

void _op_sub(stack_t **stack, unsigned int l_num)
{
	int stack_size;
	int val1;
	int val2;

	stack_size = dlistint_len(*stack);
	if (*stack == NULL || stack_size < 2)
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't sub, stack too short\n", l_num);
		exit(EXIT_FAILURE);
	}
	val1 = (*stack)->n;
	pop_dlistnode(stack);
	val2 = (*stack)->n;
	(*stack)->n = val2 - val1;
}
