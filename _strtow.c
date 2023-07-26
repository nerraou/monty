#include "lib.h"

/**
 * _substr - get sub string
 *@s: string
 *@start: start
 *@len: len
 *Return: sub string
 */
char *_substr(const char *s, int start, int len)
{
	char *str;
	int size;
	int i;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (start > size)
		return (NULL);
	if (size < len)
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}

	str[len] = '\0';
	return (str);
}

/**
 * _strclen - string length
 *@str: string
 *@set: delimiers
 *Return: string length
 */
int _strslen(const char *str, const char *set)
{
	int i;

	i = 0;
	while (str[i] && _str_index_of(set, str[i]) == -1)
		i++;
	return (i);
}

/**
 * word_count - get words count
 *@s: string
 *@set: delimiters
 *Return: string length
 */
int word_count(const char *s, const char *set)
{
	int index;
	int word;

	word = 0;
	index = 0;
	while (s[index])
	{
		while (_str_index_of(set, s[index]) != -1)
			index++;
		if (s[index])
			word++;
		while (s[index] && _str_index_of(set, s[index]) == -1)
			index++;
	}
	return (word);
}

/**
 * free_2d - free 2d array
 * @grid: 2d array
 * @height: height
 */
void free_2d(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

/**
 * strtow - split string to words
 * @str: string
 *Return: return 2d array
 */
char **_strtow(const char *str, const char *set)
{
	char **array;
	int i;
	int words;
	int start;
	int length;

	if (!str || str[0] == '\0')
		return (NULL);
	words = word_count(str, set);
	if (words == 0)
		return (NULL);
	i = 0;
	start = 0;
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (i < words)
	{
		while (str[start] == ' ' && str[start])
			start++;
		length = _strslen(str + start, set);
		array[i] = _substr(str, start, length);
		if (!array[i])
		{
			free_2d(array, i);
			return (NULL);
		}
		start += length;
		i++;
	}
	array[i] = NULL;
	return (array);
}
