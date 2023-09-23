#include "monty.h"
/**
 * opc_pall - prints all the stack elements
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * opc_pint - prints the top stack element
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * opc_pop - pops the stack elements
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
/**
 * opc_pchar - prints the char at the top of stack
 * @head: stack head
 * @line_number: the line number
 * Return: no return
*/
void opc_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
/**
 * opc_pstr - prints the str from the top of stack
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
