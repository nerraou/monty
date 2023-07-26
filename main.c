#include "lib.h"
#include "lists.h"
#include "main.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	int fd;
	char *line;
	char *trimed;
	int size;
	// int line_number;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
		printf("Error!\n");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("error!\n");
		while (1)
		{
			size = _getline(fd, &line);
			if (size == 0)
				break;
			trimed = _strtrim(line, " ");
			if (!trimed)
				break;
			_execute(trimed, &stack);
		}
	}
	return 0;
}