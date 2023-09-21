#include "monty.h"
/**
 * stp_tokerr - function that sets op_toks last element to be error code
 * @error_code: store error code string
 * Return: returns nothing
 */
void stp_tokerr(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = tokarr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));

	if (!op_toks)
	{
		malc_err();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malc_err();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
