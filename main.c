#include "monty.h"

global_t g_vars = {0};

/**
 * print_and_exit - print error and exit
 * @message: error message
 * @arg: message argument
 */
void print_and_exit(char *message, char *arg)
{
	if (arg)
	{
		fprintf(stderr, "%s %s\n", message, arg);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (g_vars.file)
			fclose(g_vars.file);
		fprintf(stderr, "%s\n", message);
		exit(EXIT_FAILURE);
	}
}

/**
 * protected_execute - free stack and string and exit
 * @trimed: trimed line
 * @stack: stack
 * @l_num: line number
 */
void protected_execute(char *trimed, stack_t **stack, int l_num)
{
	if (_execute(trimed, stack, l_num) == 0)
	{
		fclose(g_vars.file);
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
	size_t len = 0;
	ssize_t nread;
	int line_number = 1;
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
		print_and_exit("USAGE: monty file", NULL);
	g_vars.file = fopen(av[1], "r");
	if (!g_vars.file)
		print_and_exit("Error: Can't open file", av[1]);
	while (1)
	{
		line = NULL;
		len = 0;
		nread = getline(&line, &len, g_vars.file);
		if (nread <= 0)
		{
			free(line);
			break;
		}
		trimed = _strtrim(line, " \t\n\r");
		free(line);
		if (!trimed)
		{
			free_dlistint(stack);
			print_and_exit("Error: malloc failed", NULL);
		}
		if (trimed[0] != '\0')
			protected_execute(trimed, &stack, line_number);
		line_number++;
	}
	free_dlistint(stack);
	fclose(g_vars.file);
	return (EXIT_SUCCESS);
}
