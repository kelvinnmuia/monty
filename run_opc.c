#include "monty.h"
/**
* run_opc - executes the opcode
* @stack: head linked list - stack
* @line_number: the line counter
* @file: poiner to monty file
* @content: line content
* Return: returns 1 oe 0
*/
int run_opc(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opc_func[] = {
				{"push", opc_push},
				{"pall", opc_pall},
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
				{"rotl", opc_rotl},
				{"rotr", opc_rotr},
				{"queue", opc_queue},
				{"stack", opc_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bs.arg = strtok(NULL, " \n\t");
	while (opc_func[i].opcode && opc)
	{
		if (strcmp(opc, opc_func[i].opcode) == 0)
		{	opc_func[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opc && opc_func[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opc);
		fclose(file);
		free(content);
		inptr_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
