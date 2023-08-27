/**
 * File: executemonty.c
 * Auth: Tamara Lumumba
 */

#include "monty.h"
#include <string.h>

/**
 * get_op_function - Matches an opcode with its corresponding function.
 * @opcode: The opcode to find a match for.
 * Return: A pointer to the associated function, or NULL if not found.
 */
void (*get_op_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push1},
		{"pall", monty_pall1},
		{"pint", monty_pint1},
		{"pop", monty pop1},
		{"swap", monty_swap1},
		{"add", monty_add1},
		{"nop", monty_nop},
	};
	int i = 0;

	while (op_funcs[i].opcode != NULL)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].function);
		i++;
	}

	return (NULL);
}
/**
 * execute_monty - a function that executes a Monty bytecodes script.
 * @file1: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int execute_monty(FILE *file1)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initStack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &len, file1) != -1)
	{
		line_number++;
		op_toks1= tokenizeString(line, delimiters);
		if (op_toks1 == NULL)
		{
			if (isLineEmpty(line, delimiters))
				continue;
			freeStack(&stack);
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
		}
		else if (op_toks1[0][0] == '#')
		{
			releaseTokens();
			continue;
		}
			op_func = get_op_function(op_toks1[0]);
			if (op_func == NULL)
			{
				freeStack(&stack);
				exit_status = unknown_op_error(op_toks1[0], line_number);
				releaseTokens();
				break;
			}
			prev_tok_len = countTokens();
			op_func(&stack, line_number);
			if (countTokens() != prev_tok_len)
			{
				if (op_toks1 && op_toks1[prev_tok_len])
					exit_status = atoi(op_toks1[prev_tok_len]);
				else
					exit_status = EXIT_FAILURE
						releaseTokens();
				break;
			}
			releaseTokens();
	}
	freeStack(&stack);
	if (line && *line == 0)
	{
		free(line);
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}
	free(line);
	return (exit_status);
}
