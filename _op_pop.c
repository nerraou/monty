#include "monty.h"

/**
 * _op_pop - pop node
 * @stack: list head
 * @l_num: line number
 */
void _op_pop(stack_t **stack, unsigned int l_num)
{
	if (*stack == NULL)
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't pop an empty stack\n", l_num);
		exit(EXIT_FAILURE);
	}
	pop_dlistnode(stack);
}
