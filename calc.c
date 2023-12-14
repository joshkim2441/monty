#include "monty.h"

/**
 * mt_add - function to add top two elements of stack
 * @stack: a pointer to the stack top
 * @line_number: the opcode line-number
*/
void mt_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(montglb.line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	mt_pop(stack, line_number);
}

/**
 * mt_sub - a function to subtract top element of stack from second top element
 * @stack: a double pointer to the stack head
 * @line_number: a current file line number
*/
void mt_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	res = tmp->next->n - tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mt_div - function to divide second top element of stack by top element
 * @stack: a double pointer to stack head
 * @line_number: a current file line number
*/
void mt_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n / tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mt_mul - function to multiply second top element in stack with top element
 * @stack: a double pointer to stack head
 * @line_number: a current file line number
*/
void mt_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	res = tmp->next->n * tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mt_mod - function to compute modulus of second top element of
 * stack with top element
 * @stack: a pointer to the stack top
 * @line_number: the opcode line number
*/
void mt_mod(stack_t **stack, unsigned int line_number)
{
	int c, d;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;
	d = (*stack)->next->n;

	if (c == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = d % c;
	mt_pop(stack, line_number);
}
