#include "monty.h"

/* swap.c: Implements the 'swap' opcode to swap the top two stack elements */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = (*stack)->prev;
	(*stack)->prev = temp;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	*stack = temp;
}
