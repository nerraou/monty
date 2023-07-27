#include "monty.h"

/**
 * _opcode_check_error - print opcode error
 * @val: command argument
 * @index: command index
 * @l_num: line number
 * Return: 0 or 1
 */
int _opcode_check_error(const char *val, int index, int l_num)
{
	char *errors[] = {
		"usage: push integer",
	};
	if (!val || _is_int(val) == 0)
	{
		fprintf(stderr, "L%d: %s\n", l_num, errors[index]);
		return (0);
	}
	return (1);
}

/**
 * free_command - free command
 * @command: string
 */
void free_command(char **command)
{
	int i;

	i = 0;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(command);
}

/**
 * _execute - execute command
 * @command: instruction
 * @stack: stack
 * @l_num: line number
 * Return: 1: success, 0: error
 */
int _execute(const char *command, stack_t **stack, int l_num)
{
	int i;
	int error;
	char **opcode;
	instruction_t inst[] = {
		{"pall", _op_pall},
		{NULL, NULL}};

	opcode = _strtow(command, " \t\r\n");
	if (_strcmp(opcode[0], "push") == 0)
	{
		error = _opcode_check_error(opcode[1], 0, l_num);
		if (error == 1)
			_op_push(stack, atoi(opcode[1]));
		free_command(opcode);
		return (error);
	}
	i = 0;
	while (inst[i].opcode)
	{
		if (_strcmp(opcode[0], inst[i].opcode) == 0)
			break;
		i++;
	}
	if (inst[i].opcode != NULL)
		inst[i].f(stack, l_num);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, opcode[0]);
		free_command(opcode);
		return (0);
	}
	free_command(opcode);
	return (1);
}
