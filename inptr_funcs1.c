#include "monty.h"
#include <string.h>
/**
 * fr_stack - function to free stack_t
 * @stack: pointer to stack_t top or bottom elements
 * Return: returns nothing
 */
void fr_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
/**
 * initl_stack - function to initialize stack_t nodes
 * @stack: unitialized stack_t pointer
 * Return: returns EXIT_FAILURE or EXIT_SUCCESS
 */
int intl_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malc_err());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
/**
 * chck_mode - function to check the mode of stack_t
 * @stack: pointer to the stack_t
 * Return: returns 0 or 1
 */
int chck_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
