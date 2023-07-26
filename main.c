#include "lists.h"
#include "main.h"

int main(int ac, char *av[])
{
	int fd;
	char *line;
	char *trimed;
	int size;
	int line_number = 0;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
		}
		while (1)
		{
			size = _getline(fd, &line);
			if (size == 0)
				break;
			trimed = _strtrim(line, " \t\n");
			free(line);
			if (!trimed)
			{
				free(line);
				free_dlistint(stack);
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			_execute(trimed, &stack);
			free(trimed);
			line_number++;
		}
		free_dlistint(stack);
	}
	return 0;
}