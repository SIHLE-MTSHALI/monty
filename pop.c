#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script
 * @arg: Unused argument
 */
void pop(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *temp;

	(void)arg;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

