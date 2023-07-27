#include "monty.h"

/**
 * _isspace - check if a given character is whitespace
 * @c: character
 * Return: true: if space, false: if not
 */
int _isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
