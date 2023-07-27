#include "monty.h"

/**
 * free_args - free args
 * @args: string
 */
void free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
