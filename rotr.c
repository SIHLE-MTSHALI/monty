#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script (unused)
 * @arg: Unused argument
 */
void rotr(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *last, *second_last;

	(void)line_number;
	(void)arg;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	last = *stack;
	while (last->next)
		last = last->next;

	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

