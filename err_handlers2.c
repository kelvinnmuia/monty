#include "monty.h"

/**
 * pop_err - err function to handle error when poping a stack
 * @line_number: line number where error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pint_err - err function to handle pint function errors
 * @line_number: line number where error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int pint_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * smstack_err - err function to handle stack/queue less than 2 nodes
 * @line_number: line number where error is encountered
 * @op: operation where the code is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int smstack_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack is too short\n", line_number, op);
	return (EXIT_FAILURE);
}
/**
 * div_err - err function to handle division errors
 * @line_number: line number where error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pchar_err - err function to handle pchar function errors
 * @line_number: line number where the error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int pchar_err(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
