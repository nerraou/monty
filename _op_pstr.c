#include "monty.h"

/**
 * _op_pstr - print string starting at the top
 * @stack: list head
 * @l_num: line number
 */
void _op_pstr(stack_t **stack, unsigned int l_num)
{
	stack_t *it;

	(void)l_num;
	it = *stack;
	while (it && it->n != 0 && isascii(it->n))
	{
		printf("%c", it->n);
		it = it->next;
	}
	printf("\n");
}
