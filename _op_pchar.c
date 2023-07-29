#include "monty.h"

/**
 * _op_pchar - print top as char
 * @stack: list head
 * @l_num: line number
 */
void _op_pchar(stack_t **stack, unsigned int l_num)
{
	int n;

	if (*stack == NULL)
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l_num);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (!isascii(n))
	{
		free_args(g_vars.args);
		fclose(g_vars.file);
		fprintf(stderr, "L%u: can't pchar, value out of range\n", l_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}
