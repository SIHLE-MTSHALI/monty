#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the script (unused)
 * @arg: Unused argument
 */
void pstr(stack_t **stack, unsigned int line_number, const char *arg)
{
	stack_t *current;

	(void)line_number;
	(void)arg;

	current = *stack;
	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", (char)(current->n));
		current = current->next;
	}
	printf("\n");
}

