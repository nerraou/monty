#include "monty.h"

int fd = -1;

/**
 * print_and_exit - print error and exit
 * @message: error message
 * @arg: message argument
 * @fd: file handle
 */
void print_and_exit(char *message, char *arg)
{
	if (fd >= 0)
		close(fd);
	if (arg)
	{
		fprintf(stderr, "%s %s\n", message, arg);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "%s\n", message);
		exit(EXIT_FAILURE);
	}
}

/**
 * protected_execute - free stack and string and exit
 * @trimed: trimed line
 * @stack: stack
 * @l_num: line number
 * @fd: file handle
 */
void protected_execute(char *trimed, stack_t **stack, int l_num)
{
	if (_execute(trimed, stack, l_num) == 0)
	{
		close(fd);
		free(trimed);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - check the code
 * @ac: arguments count
 * @av: arguments value
 * Return: Always EXIT_SUCCESS.
 */
int main(int ac, char *av[])
{
	char *line;
	char *trimed;
	int size;
	int line_number = 1;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
		print_and_exit("USAGE: monty file", NULL);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			print_and_exit("Error: Can't open file", av[1]);
		while (1)
		{
			size = _getline(fd, &line);
			if (size == -1)
				print_and_exit("Error: malloc failed", NULL);
			if (size == 0)
				break;
			trimed = _strtrim(line, " \t\n\r");
			free(line);
			if (!trimed)
			{
				free_dlistint(stack);
				print_and_exit("Error: malloc failed", NULL);
			}
			if (trimed[0] != '\0')
				protected_execute(trimed, &stack, line_number);
			free(trimed);
			line_number++;
		}
		free_dlistint(stack);
		close(fd);
	}
	return (EXIT_SUCCESS);
}
