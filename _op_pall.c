#include "monty.h"

/**
 * _op_pall - print list
 * @stack: list head
 * @l_num: line number
 */
void _op_pall(stack_t **stack, unsigned int l_num)
{
	(void)l_num;
	print_dlistint(*stack);
}
