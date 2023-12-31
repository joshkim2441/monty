#include "monty.h"

/**
 * mt_rotr - rotates stack to the top
 * @stack: the stack head
 * @line_number: the line number
 * Return: none
*/
void mt_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (tmp->next)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

/**
 * mt_rotl - rotates stack to the bottom
 * @stack: the stack head
 * @line_number: the line number
 * Return: none
*/
void mt_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *curr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	curr = (*stack)->next;
	curr->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = curr;
}

/**
 * mt_queue - function to print the top
 * @stack: the stack head
 * @line_number: the opcode line number
 * Return: none
*/
void mt_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	montglb.lifo = 0;
}

/**
 * que_add - function to add a node to the stack tail
 * @n: the new node
 * @stack: the stack head
 * Return: none
*/
void que_add(stack_t **stack, int n)
{
	stack_t *n_node, *curr;

	curr = *stack;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		printf("Error\n");
	}
	n_node->n = n;
	n_node->next = NULL;
	if (curr)
	{
		while (curr->next)
			curr = curr->next;
	}
	if (!curr)
	{
		*stack = n_node;
		n_node->prev = NULL;
	}
	else
	{
		curr->next = n_node;
		n_node->prev = curr;
	}
}
