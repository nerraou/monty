#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 5

extern int fd;

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

int _execute(const char *command, stack_t **stack, int l_num);

void _op_push(stack_t **stack, unsigned int n);
void _op_pall(const stack_t *stack);

int _getline(int fd, char **linep);
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
unsigned int _atou(const char *str);

#endif /* MONTY_H */
