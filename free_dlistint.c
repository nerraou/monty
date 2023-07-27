#include "monty.h"

/**
 * free_dlistint - free list
 * @head: list head
 */
void free_dlistint(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
