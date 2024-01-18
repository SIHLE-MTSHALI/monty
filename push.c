#include "monty.h"

/* push.c: Implements the 'push' opcode to push an element to the stack */

void push(stack_t **stack, unsigned int line_number, const int n)
{
	stack_t *new_node;

	(void)line_number; /* To avoid unused parameter warning */

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
