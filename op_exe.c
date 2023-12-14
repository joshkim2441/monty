#include "monty.h"

/**
 * file_exe - function to read and execute opcodes
 * @stack: a pointer to the top of the stack
*/
void file_exe(stack_t **stack)
{
	size_t length = 0;
	ssize_t cread;
	char *opcode = NULL;
	unsigned int line_number = 0;

	while ((cread = getline(&montglb.line, &length, montglb.file)) != -1)
	{
		line_number++;
		opcode = strtok(montglb.line, " \t\r\n\a");
		montglb.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		opcode_exe(opcode, stack, line_number);
	}
}

/**
 * opcode_exe - a function to execute a single opcode
 * @opcode: the opcode to execute
 * @stack: a pointer to the stack top
 * @line_number: the opcode line-number
*/
void opcode_exe(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
	    {"push", mt_push},
	    {"pall", mt_pall},
	    {"pint", mt_pint},
	    {"pop", mt_pop},
	    {"swap", mt_swap},
	    {"nop", mt_nop},
	    {"add", mt_add},
	    {"sub", mt_sub},
	    {"div", mt_div},
	    {"mul", mt_mul},
	    {"mod", mt_mod},
	    {"pchar", mt_pchar},
	    {"pstr", mt_pstr},
	    {NULL, NULL}
	};
	int j;

	for (j = 0; instructions[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, instructions[j].opcode) == 0)
		{
			instructions[j].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: Unknown instruction %s\n", line_number, opcode);
	stack_free(*stack);
	fclose(montglb.file);
	free(montglb.line);
	exit(EXIT_FAILURE);
}

/**
 * adnode - function to add a node at the start of the stack_t list
 * @stack: a pointer to a pointer of the stack top
 * @n: a value addedd to new node
 * Return: the new node
*/
stack_t *adnode(stack_t **stack, const int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}

	n_node->n = n;
	n_node->prev = NULL;

	if (*stack == NULL)
		n_node->next = NULL;
	else
	{
		n_node->next = *stack;
		(*stack)->prev = n_node;
	}
	*stack = n_node;

	return (n_node);
}

/**
 * stack_free - function to free a stack_t list
 * @stack: a pointer to the stack top
*/
void stack_free(stack_t *stack)
{
	stack_t *curr;

	while (stack != NULL)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}
}
