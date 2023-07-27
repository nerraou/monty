#include "monty.h"

/**
 * _opcode_check_error - print opcode error
 * @val: command argument
 * @l_num: line number
 * Return: 0 or 1
 */
int _opcode_check_error(const char *val, int l_num)
{
	if (!val || _is_int(val) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_num);
		return (0);
	}
	return (1);
}

/**
 * _execute - execute command
 * @command: instruction
 * @stack: stack
 * @l_num: line number
 * Return: 1: success, 0: error
 */
int _execute(char *command, stack_t **stack, int l_num)
{
	int i;
	int error;
	instruction_t inst[] = {
		{"pall", _op_pall}, {"pint", _op_pint}, {"pop", _op_pop},
		{"swap", _op_swap}, {"add", _op_add}, {"nop", _op_nop},
		{"sub", _op_sub},
		{NULL, NULL}};

	g_vars.args = _strtow(command, " \t\r\n");
	free(command);
	if (_strcmp(g_vars.args[0], "push") == 0)
	{
		error = _opcode_check_error(g_vars.args[1], l_num);
		if (error == 1)
			_op_push(stack, atoi(g_vars.args[1]));
		free_args(g_vars.args);
		return (error);
	}
	i = 0;
	while (inst[i].opcode)
	{
		if (_strcmp(g_vars.args[0], inst[i].opcode) == 0)
			break;
		i++;
	}
	if (inst[i].opcode != NULL)
		inst[i].f(stack, l_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, g_vars.args[0]);
		free_args(g_vars.args);
		return (0);
	}
	free_args(g_vars.args);
	return (1);
}
