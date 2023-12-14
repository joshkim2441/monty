#include "monty.h"

montglb_t montglb;

/**
 * main - monty program entry point
 * @argc: command line argument count
 * @argv: an array of argument strings in command line
 * Return: 0 for success
*/
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montglb.file = fopen(argv[1], "r");
	if (montglb.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	file_exe(&stack);
	fclose(montglb.file);
	free(montglb.line);
	stack_free(stack);
	exit(EXIT_FAILURE);
}
