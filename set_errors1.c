/*
 * File: set_errors1.c
 * Auth: Tamara Lumumba
 */

#include "monty.h"

/**
 * set_error1 - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in inst_toks1.
 */
void set_error1(int error_code)
{
	int tok_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	tok_len = countTokens();
	new_toks = malloc(sizeof(char *) * (tok_len + 2));
	if (!op_toks1)
	{
		malloc_error();
		return;
	}
	while (i < tok_len)
	{
		new_toks[i] = op_toks1[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks1);
	op_toks1 = new_toks;
}
