#include "monty.h"
/**
 * opc_nop - function that does nothing for nop monty opcode
 * @stack: a pointer to the top node of stack_t
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * opc_pchar - function that prints character in the top value of stack_t
 * @stack: pointer to the top node of stack_t
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		stp_tokerr(pchar_err(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		stp_tokerr(pchar_err(line_number, "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}
/**
 * opc_pstr - function that prints string in stack_t
 * @stack: pointer to the top node of stack_t
 * @line_number: the working line number of monty bytecode
 * Return: returns nothing
 */
void opc_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
