#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of stack or queue
 * @n: integer
 * @prev: pointer to previous element of stack or queue
 * @next: pointer to next element of stack or queue
 * Description: a doubly linked list node structure for a stack,
 * queues, LIFO, FIFO Holberton project
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
 * Description: opcode and its function for stack, queue, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct montglb_s - the variables args, line and file
 * @file: a pointer to a monty file
 * @line: the content for the input line
 * @arg: a value
 * @fili: stack queue flag change
 * Description: the variables that carry values in the program
*/
typedef struct montglb_s
{
	char *line;
	char *arg;
	FILE *file;
	int fili;
} montglb_t;

extern montglb_t montglb;

void file_exe(stack_t **stack);
void opcode_exe(char *opcode, stack_t **stack, unsigned int line_number);

void mt_push(stack_t **stack, unsigned int line_number);
void mt_pall(stack_t **stack, unsigned int line_number);
void mt_pint(stack_t **stack, unsigned int line_number);
void mt_pop(stack_t **stack, unsigned int line_number);
void mt_swap(stack_t **stack, unsigned int line_number);
void mt_add(stack_t **stack, unsigned int line_number);
void mt_nop(stack_t **stack, unsigned int line_number);
void mt_sub(stack_t **stack, unsigned int line_number);
void mt_div(stack_t **stack, unsigned int line_number);
void mt_mul(stack_t **stack, unsigned int line_number);
void mt_mod(stack_t **stack, unsigned int line_number);
void mt_pchar(stack_t **stack, unsigned int line_number);
void mt_pstr(stack_t **stack, unsigned int line_number);

stack_t *adnode(stack_t **stack, const int n);
int is_digit(char *s);
void stack_free(stack_t *stack);

void mt_rotl(stack_t **, __attribute__((unused)) unsigned int);
void mt_rotr(stack_t **, __attribute__((unused)) unsigned int);

#endif /*MONTY_H*/
