#define _POSIX_C_SOURCE 200809L
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void free_stack(stack_t *stack);
void (*get_op_func(char *opcode))(stack_t **, unsigned int, const char *);

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *opcode, *arg;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*op_func)(stack_t **, unsigned int, const char *);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (!opcode || opcode[0] == '#')
			continue;

		op_func = get_op_func(opcode);
		if (!op_func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(line);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		arg = strtok(NULL, " \n\t");
		op_func(&stack, line_number, arg);
	}

	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees a stack
 * @stack: The stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

/**
 * get_op_func - Selects the correct function to perform the operation
 * @opcode: Opcode to parse
 * Return: Pointer to the function corresponding to the opcode
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int, const char *)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
	}

	return (NULL);
}

