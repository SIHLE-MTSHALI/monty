#include "monty.h"

/* monty_run.c: Executes Monty bytecode instructions from a file */

void monty_run(const char *file_path)
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * 1024); /* Arbitrary size */
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((fgets(line, 1024, file)) != NULL)
	{
		line_number++;
		/* Parse and execute instructions */
	}

	free(line);
	fclose(file);
	free_stack(&stack);
}
