#include "monty.h"
/**
 * opc_push - function that pushes values to stack_t
 * @stack: pointer to stack_t top node
 * @line_number: line number of the bytecode file
 * Return: returns nothing
 */
void opc_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		stp_tokerr(malc_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		stp_tokerr(nint_err(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			stp_tokerr(nint_err(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	/*insert values at the front when in STACK mode*/
	if (chck_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /*insert values at the end when in QUEUE mode*/
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
/**
 * opc_pall - function to print all stack_t values
 * @stack: pointer to stack_t top node
 * @line_number: the line number of the bytecode file
 */
void opc_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * opc_pint - function to print stack_t top value
 * @stack: pointer to stack_t top node
 * @line_number: the line number of the bytecode file
 */
void opc_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		stp_tokerr(pint_err(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
/**
 * opc_pop - function to remove top stack_t values
 * @stack: pointer to stack_t top node
 * @line_number: the line number of the bytecode file
 */
void opc_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		stp_tokerr(pop_err(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * opc_swap - function to swap two stack_t values
 * @stack: pointer to stack_t top node
 * @line_number: the line number of the bytecode file
 */
void opc_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		stp_tokerr(smstack_err(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
