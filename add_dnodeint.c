#include "monty.h"

/**
 * add_dnodeint - add node
 * @head: list head
 * @n: value
 * Return: new node
 */
stack_t *add_dnodeint(stack_t **head, unsigned int n)
{
	stack_t *node;

	if (!head)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = (*head);

	if ((*head))
		(*head)->prev = node;
	(*head) = node;
	return (node);
}
