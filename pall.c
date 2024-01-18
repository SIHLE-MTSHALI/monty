#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

