#include "monty.h"

/* 
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the script for error reporting.
 * @n: The integer to be pushed onto the stack.
 */
void push(stack_t **stack, unsigned int line_number, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
