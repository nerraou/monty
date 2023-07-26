#include "main.h"

int _execute(const char *command, stack_t **stack)
{
	int i;
	instruction_t inst[] =
		{
			{.opcode = "push", .f = _op_push},
			{NULL, NULL}};

	char **opcode = _strtow(command, " \t");
	if (_strcmp(opcode[0], "pall") == 0)
	{
		_op_pall(*stack);
		return 1;
	}

	i = 0;
	while (inst[i].opcode)
	{
		if (_strcmp(opcode[0], inst[i].opcode) == 0)
		{
			break;
		}
		i++;
	}
	if (inst[i].opcode != NULL)
	{
		if (_is_int(opcode[1]))
			inst[i].f(stack, _atou(opcode[1]));
	}
	return 1;
}
