#include "monty.h"

/**
 * opc_rot1 - function that rotates top value of stack_t
 * @stack: a pointer to the stack_t top node
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_rot1(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
/**
 * opc_rotr - function that rotates bottom value of stack_t
 * @stack: a pointer to the stack_t top node
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
/**
 * opc_stack - function to convert a queue into stack
 * @stack: pointer to the stack_t top node
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * opc_queue - function to convert a stack into a queue
 * @stack: pointer to the stack_t top node
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
