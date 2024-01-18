#include "monty.h"

/* add.c: Implements the 'add' opcode to add the top two stack elements */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = temp->n + temp->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
