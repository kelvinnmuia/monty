#include "monty.h"
/**
 * opc_add - function to add top stack_t values
 * @stack: pointer to the top node of stack_t
 * @line_number: monty bytecode working line number
 *
 * Description: results are stored in the preceeding node
 *
 * Return: returns nothing
 */
void opc_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(smstack_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	opc_pop(stack, line_number);

}
/**
 * opc_sub - function to subtract stack_t values
 * @stack: pointer to the top node of stack_t
 * @line_number: monty bytecode working line number
 *
 * Description: results are stored in the preceeding node
 *
 * Return: returns nothing
 */
void opc_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(smstack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	opc_pop(stack, line_number);
}
/**
 * opc_div - function to divide stack_t values
 * @stack: pointer to the top node of the stack_t
 * @line_number: monty bytecode working line number
 *
 * Description: results are stored in preceeding node
 *
 * Return: returns nothing
 */
void opc_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(div_err(line_number));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		stp_tokerr(div_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	opc_pop(stack, line_number);
}
/**
 * opc_mul - function to multiply stack_t values
 * @stack: pointer to the top node of the stack_t
 * @line_number: monty bytecode working line number
 *
 * Description: results are stored in preceeding node
 *
 * Return: returns nothing
 */
void opc_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(smstack_err(line_number, "mul"));
		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	opc_pop(stack, line_number);
}
/**
 * opc_mod - function to find modulous of stack_t values
 * @stack: pointer to the top node of the stack_t
 * @line_number: monty bytecode working line number
 *
 * Description: results are stored in preceeding node
 * Return: returns nothing
 */
void opc_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(smstack_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		stp_tokerr(div_err(line_number));
		return;
	}
}
