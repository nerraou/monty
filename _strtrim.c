#include "monty.h"

/**
 * _isexists - check is exist
 * @s1: string
 * @c: char
 *Return: 1 or 0
 */
int _isexists(char const *s1, char c)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtrimlen - count string length
 * @s1: string
 * @set: string
 *Return: len of trimed string
 */
size_t _strtrimlen(char const *s1, char const *set)
{
	size_t len;
	size_t total_len;
	size_t i;
	int t;

	i = 0;
	t = 0;
	len = _strlen(s1);
	if (len == 0)
		return (0);
	total_len = len;
	while (s1[i])
	{
		if (!_isexists(set, s1[i]))
			break;
		i++;
		t++;
	}
	while (--len > i)
	{
		if (!_isexists(set, s1[len]))
			break;
		t++;
	}
	return (total_len - t);
}

/**
 * _strtrim - trim a string
 * @s1: string
 * @set: string
 *Return: trimed string
 */
char *_strtrim(char const *s1, char const *set)
{
	size_t len;
	char *tab;
	int i;

	i = 0;
	len = _strtrimlen(s1, set);
	if (len == 0)
		return (_strdup(""));
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		if (!_isexists(set, s1[i]))
			break;
		i++;
	}
	_strncpy(tab, s1 + i, len);
	tab[len] = '\0';
	return (tab);
}
