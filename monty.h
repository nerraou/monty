#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

/**
 * struct globals - global structure to use in the functions
 * @args: opcodes
 * @file: fd
 *
 * Description: global variables
 */
typedef struct globals
{
	char **args;
	FILE *file;
} global_t;

extern global_t g_vars;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_dnodeint(stack_t **head, unsigned int n);
size_t print_dlistint(const stack_t *h);
void free_dlistint(stack_t *head);
void pop_dlistnode(stack_t **stack);

int _execute(char *command, stack_t **stack, int l_num);

void _op_push(stack_t **stack, int n);
void _op_pall(stack_t **stack, unsigned int l_num);
void _op_pint(stack_t **stack, unsigned int l_num);
void _op_pop(stack_t **stack, unsigned int l_num);

ssize_t _str_index_of(const char *str, char c);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *join_and_free(char *s1, const char *s2);
char *strjoin(const char *s1, const char *s2);
size_t _strlen(const char *str);
char *_strtrim(char const *s1, char const *set);
char *_strncpy(char *dest, const char *src, size_t n);
char **_strtow(const char *str, const char *set);
int _strcmp(char *s1, char *s2);
int _isspace(char c);
int _is_int(const char *str);
void free_args(char **args);

#endif /* MONTY_H */
