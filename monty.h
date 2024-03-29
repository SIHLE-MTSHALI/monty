#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, const char *arg);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, const char *arg);
void pall(stack_t **stack, unsigned int line_number, const char *arg);
void pint(stack_t **stack, unsigned int line_number, const char *arg);
void pop(stack_t **stack, unsigned int line_number, const char *arg);
void swap(stack_t **stack, unsigned int line_number, const char *arg);
void add(stack_t **stack, unsigned int line_number, const char *arg);
void nop(stack_t **stack, unsigned int line_number, const char *arg);
void sub(stack_t **stack, unsigned int line_number, const char *arg);
void div_op(stack_t **stack, unsigned int line_number, const char *arg);
void mul(stack_t **stack, unsigned int line_number, const char *arg);
void mod(stack_t **stack, unsigned int line_number, const char *arg);
void pchar(stack_t **stack, unsigned int line_number, const char *arg);
void pstr(stack_t **stack, unsigned int line_number, const char *arg);
void rotl(stack_t **stack, unsigned int line_number, const char *arg);
void rotr(stack_t **stack, unsigned int line_number, const char *arg);



#endif /* MONTY_H */

