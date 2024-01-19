#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script (unused)
 * @arg: Unused argument
 */
void rotl(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *first, *last;

	(void)line_number;
	(void)arg;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	first = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

