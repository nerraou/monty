#include "lib.h"

/**
 * _strncpy - copy string
 * @dest: string
 * @src: string
 * @n: int
 *Return: new copy of str
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}