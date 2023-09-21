#include "monty.h"
#include <string.h>

/**
 * fr_toks - function to free the global op_toks array
 * Return: returns nothing
 */
void fr_toks(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}
/**
 * tokarr_len - function that determines op_toks length
 *
 * Return: returns the length of op_toks
 */
unsigned int tokarr_len(void)
{
	unsigned int tokslen = 0;

	while (op_toks[tokslen])
		tokslen++;
	return (tokslen);
}
/**
 * isempty_ln - checks whether the line read has delims
 * @line: pointer to the line
 * @delims: string of delim characters
 *
 * Return: returns 0 or 1
 */
int isempty_ln(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}
/**
 * gtop_func - function that matches opcode with corresponding function
 * @opcode: opcode to match
 *
 * Return: returns corresponding opcode function
 */
void (*gtop_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opcd_funcs[] = {
		{"pall", opc_pall},
		{"push", opc_push},
		{"pint", opc_pint},
		{"pop", opc_pop},
		{"swap", opc_swap},
		{"add", opc_add},
		{"nop", opc_nop},
		{"sub", opc_sub},
		{"div", opc_div},
		{"mul", opc_mul},
		{"mod", opc_mod},
		{"pchar", opc_pchar},
		{"pstr", opc_pstr},
		{"rot1", opc_rot1},
		{"rotr", opc_rotr},
		{"stack", opc_stack},
		{"queue", opc_queue},
		{NULL, NULL}

	};
	int i;

	for (i = 0; opcd_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, opcd_funcs[i].opcode) == 0)
			return (opcd_funcs[i].f);
	}

	return (NULL);
}
/**
 * rn_mn - function to execute the bytecode file
 * @mscrpt_fd: the file descriptor for the open bytecode file
 *
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int rn_mn(FILE *mscrpt_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_toklen = 0;
	void (*opcd_funcs)(stack_t**, unsigned int);

	if (initl_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, mscrpt_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (isempty_ln(line, DELIMS))
				continue;
			fr_stack(&stack);
			return (malc_err());
		}
		else if (op_toks[0][0] == '#') /*comments*/
		{
			fr_toks();
			continue;

		}
		opcd_funcs = gtop_func(op_toks[0]);
		if (opcd_funcs == NULL)
		{
			fr_stack(&stack);
			exit_status = unopc_err(op_toks[0], line_number);
			fr_toks();
			break;
		}
		prev_toklen = tokarr_len();
		opcd_funcs(&stack, line_number);
		if (tokarr_len() != prev_toklen)
		{
			if (op_toks && op_toks[prev_toklen])
				exit_status = atoi(op_toks[prev_toklen]);
			else
				exit_status = EXIT_FAILURE;
			fr_toks();
			break;
		}
		fr_toks();
	}
	fr_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malc_err());
	}

	free(line);
	return (exit_status);
}
