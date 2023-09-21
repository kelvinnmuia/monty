#include "monty.h"

/**
 * usg_err - err function to handle usage errors
 * Return: returns EXIT_FAILURE
 */
int usg_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malc_err - err function to handle malloc errors
 * Return: returns EXIT_FAILURE
 */
int malc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
 * filop_err - err function to handle file opening errors
 * @filename: name of file failing to open
 * Return: returns EXIT_FAILURE
 */
int filop_err(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
/**
 * unopc_err - err function to handle unknown opcode errors
 * @opcode: the opcode where an error is encountered
 * @line_number: line number where the error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int unopc_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instructions %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}
/**
 * nint_err - err function to handle invalid monty_push argument errors
 * @line_number: line number where the error is encountered
 *
 * Return: returns EXIT_FAILURE
 */
int nint_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
