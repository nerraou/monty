#include "main.h"

void _opcode_check_error(char *val, int index, int l_num)
{
	char *errors[] = {
		"usage: push integer",
	};
	if (_is_int(val) == 0)
	{
		fprintf(stderr, "L%d: %s\n", l_num, errors[index]);
		exit(EXIT_FAILURE);
	}
}

int _execute(const char *command, stack_t **stack, int l_num)
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
		_opcode_check_error(opcode[1], i, l_num);

		inst[i].f(stack, _atou(opcode[1]));
	}
	return 1;
}
