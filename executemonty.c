#include "monty.h"

/**
 * get_op_function - Matches an opcode with its corresponding function.
 * @opcode: The opcode to find a match for.
 * Return: A pointer to the associated function, or NULL if not found.
 */
void (*get_op_function(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opst[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},
		{"queue", f_queue},
		{"stack", f_stack},
		{NULL, NULL}
	};
	int i = 0;

	while (opcode_functions[i].opcode != NULL)
	{
		if (strcmp(opcode, opcode_functions[i].opcode) == 0)
			return (opcode_functions[i].function);
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
		inst_toks1 = strtow(line, delimiters);
		if (inst_toks1 == NULL)
		{
			if (isLineEmpty(line, delimiters))
				continue;
			freeStack(&stack);
			fprintf(stderr, "Error: malloc failed\n");
			return (EXIT_FAILURE);
		}
		else if (inst_toks1[0][0] == '#')
		{
			releaseTokens();
			continue;
		}
			op_func = get_op_function(inst_toks1[0]);
			if (op_func == NULL)
			{
				freeStack(&stack);
				exit_status = unknown_op_error(inst_toks1[0], line_number);
				releaseTokens();
				break;
			}
			prev_tok_len = countTokens();
			op_func(&stack, line_number);
			if (countTokens() != prev_tok_len)
			{
				if (inst_toks1 && inst_toks1[prev_tok_len])
					exit_status = atoi(inst_toks1[prev_tok_len]);
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
