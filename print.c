#include "monty.h"

/**
 * mt_pall - function to print all values on stack
 * @stack: a pointer to top of stack
 * @line_number: the opcode line number
*/
void mt_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		(void)line_number;
	}
}

/**
 * mt_pchar - function that prints the character at top of stack
 * @stack: a pointer to stack top
 * @line_number: current line number of opcode in Monty file
*/
void mt_pchar(stack_t **stack, unsigned int line_number)
{
	int val;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = (*stack)->n;
	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", val);
}

/**
 * mt_pint - function to print the value at the stack top
 * @stack: a pointer to the stack top
 * @line_number: the opcode line number
*/
void mt_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(montglb.line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * mt_pstr - function to print string from stack top
 * followed by new line
 * @stack: a double pointer to the stack top
 * @line_number: the opcode line number in Monty file
*/
void mt_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	while (curr && curr->n > 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}

/**
 * mt_stack - function to print the top
 * @stack: the stack head
 * @line_number: the line number
 * Return: none
*/
void mt_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	montglb.fili = 0;
}
