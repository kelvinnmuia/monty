#include "monty.h"
/**
  *opc_rotl- rotates the stack to the top
  *@head: stack head
  *@line_number: the line number
  *Return: returns nothing
 */
void opc_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
/**
  *opc_rotr- rotates the stack to the bottom
  *@head: stack head
  *@line_number: the line number
  *Return: returns nothing
 */
void opc_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
/**
 * opc_push - add node to the stack
 * @head: stack head
 * @line_number: the line number
 * Return: returns nothing
*/
void opc_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (bs.arg)
	{
		if (bs.arg[0] == '-')
			j++;
		for (; bs.arg[j] != '\0'; j++)
		{
			if (bs.arg[j] > 57 || bs.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bs.file);
			free(bs.content);
			inptr_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bs.file);
		free(bs.content);
		inptr_free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bs.arg);
	if (bs.swt_mode == 0)
		inptr_addnode(head, n);
	else
		inptr_addqueue(head, n);
}
