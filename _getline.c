
#include "lib.h"

/**
 * get_line_from_buffer - get line from buffer
 * @buffer: buffer
 * @line: line pointer
 * @linep: line pointer
 * Return: -1: on error, 0: no new line found, 1: on success
 */
int get_line_from_buffer(char *buffer, char **line, char **linep)
{
	ssize_t nl_index;

	nl_index = _str_index_of(buffer, '\n');
	if (nl_index != -1)
		buffer[nl_index] = '\0';
	*line = join_and_free(*line, buffer);
	if (*line == NULL)
		return (-1);
	if (nl_index != -1)
	{
		_strcpy(buffer, buffer + nl_index + 1);
		*linep = *line;
		return (1);
	}
	return (0);
}

/**
 * _getline - read next line from fd
 * @fd: file handle
 * @linep: line pointer
 * Return: -1: on error, 0: when eof reached, 1: on success
 */
int _getline(int fd, char **linep)
{
	static char buffer[BUFFER_SIZE + 1] = {0};
	ssize_t nl_index;
	ssize_t read_bytes;
	char *line;
	int get_line_return;

	nl_index = _str_index_of(buffer, '\n');
	if (nl_index != -1)
	{
		buffer[nl_index] = '\0';
		*linep = _strdup(buffer);
		_strcpy(buffer, buffer + nl_index + 1);
		return (1);
	}
	line = _strdup(buffer);
	buffer[0] = '\0';
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			get_line_return = line[0] != '\0';
			if (line[0] != '\0')
				*linep = line;
			else
				free(line);
			return (get_line_return);
		}
		buffer[read_bytes] = '\0';
		if (read_bytes > 0)
		{
			get_line_return = get_line_from_buffer(buffer, &line, linep);
			if (get_line_return != 0)
				return (get_line_return);
		}
	}
	return (0);
}