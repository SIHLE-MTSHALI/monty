#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script
 * @arg: The integer to push
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	long num;
	char *endptr;
	stack_t *new_node;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = strtol(arg, &endptr, 10);
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = (int)num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

