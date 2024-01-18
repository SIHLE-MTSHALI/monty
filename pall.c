#include "monty.h"

/* pall.c: Implements the 'pall' opcode to print all stack elements */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* To avoid unused parameter warning */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
