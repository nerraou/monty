#include "monty.h"

/**
 * _op_pint - print top
 * @stack: list head
 * @l_num: line number
 */
void _op_pint(stack_t **stack, unsigned int l_num)
{
	if (*stack == NULL)
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
