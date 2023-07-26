#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#include "lib.h"
#include "lists.h"
#include "opcode.h"

int _execute(const char *command, stack_t **stack);

void _op_push(stack_t **stack, unsigned int n);
void _op_pall(const stack_t *stack);

#endif /* MAIN_H */
