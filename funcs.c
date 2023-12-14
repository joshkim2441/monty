#include "monty.h"

/**
 * mt_nop - nothing happens
 * @stack: a pointer to the stack top
 * @line_number: the opcode line number
*/
void mt_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * mt_pop - function to remove the stack top element
 * @stack: a pointer to the stack top
 * @line_number: the opcode line number
*/
void mt_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(montglb.line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next; /*point to next node*/
	free(*stack); /*free current allocated mem*/
	*stack = tmp; /*update pointer to new node*/
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * mt_push - function to push an element onto stack
 * @stack: a pointer to the stack top
 * @line_number: the opcode current line number in Monty file
*/
void mt_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (montglb.arg == NULL || !is_digit(montglb.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		stack_free(*stack);
		fclose(montglb.file);
		free(montglb.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(montglb.arg);
	if (adnode(stack, n) == NULL)
	{
		fprintf(stderr, "Error:malloc failed\n");
		stack_free(*stack);
		fclose(montglb.file);
		free(montglb.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * mt_swap - function to swap top two elements of stack
 * @stack: a pointer to the stack top
 * @line_number: the opcode line number
*/
void mt_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(montglb.line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)

	tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * is_digit - function to check if a string is a digit
 * @s: the string to be checked
 * Return: if string is a digit 1, otherwise 0
*/
int is_digit(char *s)
{
	if (s == NULL || *s == '\0')
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
