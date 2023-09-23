#include "monty.h"
/**
  *opc_nop- no operations functions
  *@head: stack head
  *@line_number: the line number
  *Return: returns nothing
 */
void opc_nop(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;
}
/**
 * opc_queue - switches the stack_t to queue
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bs.swt_mode = 1;
}
/**
 * opc_stack - prints the top
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bs.swt_mode = 0;
}
/**
 * opc_swap - swaps two stack elements
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
