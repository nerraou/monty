#include "monty.h"

/**
 * _is_int - check if str contains integer
 * @str: string
 * Return: true if str is integer, otherwise false
 */
int _is_int(const char *str)
{
	int i;

	i = 0;
	while (_isspace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		i++;
	}
	while (_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
