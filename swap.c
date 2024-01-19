#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script
 * @arg: Unused argument
 */
void swap(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *temp;

	(void)arg;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	temp->prev = (*stack)->prev;
	(*stack)->prev = temp;
	*stack = temp;
}

