#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

char **op_toks = NULL;

/**
 * main - bytecode intepreter entry point
 * @argc: counter for arguments passed to the program
 * @argv: double pointer to an arguments array
 *
 * Return: returns EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	FILE *mscrpt_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usg_err());
	mscrpt_fd = fopen(argv[1], "r");
	if (mscrpt_fd == NULL)
		return (filop_err(argv[1]));
	exit_code = rn_mn(mscrpt_fd);
	fclose(mscrpt_fd);
	return (exit_code);
}
