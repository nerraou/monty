#include "monty.h"

/**
 * _atou - convert string to integer
 * @str: string
 * Return: parsed value
 */
unsigned int _atou(const char *str)
{
	unsigned int n;
	int i;

	n = 0;
	i = 0;
	while (_isspace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}
