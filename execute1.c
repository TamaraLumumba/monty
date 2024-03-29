/*
 * File: execute1.c
 * Auth: Tamara Lumumba
 */

#include "monty.h"
#include <string.h>

void releaseTokens(void);
unsigned int countTokens(void);
int isLineEmpty(char *line, char *delimiters);

/**
 * releaseTokens - Deallocates memory for the global instruction token array.
 */
void releaseTokens(void)
{
	int i;

	if (op_toks1 == NULL)
		return;

	for (i = 0; op_toks1[i]; i++)
		free(op_toks1[i]);

	free(op_toks1);
}

/**
 * countTokens - Determines the count of tokens in the inst_toks1 array.
 * Return: Number of tokens in the inst_toks1 array (as an unsigned int).
 */

unsigned int countTokens(void)
{
	unsigned int tokensCount = 0;

	do {
		tokensCount++;
	} while (op_toks1[tokensCount]);

	return (tokensCount);
}

/**
 * isLineEmpty - Checks if a line contains only delimiter characters.
 * @line: Pointer to the line to be checked.
 * @delimiters: String of delimiter characters.
 * Return: 1 if the line only contains delimiters, 0 otherwise.
 */

int isLineEmpty(char *line, char *delimiters)
{
	int i = 0;

	while (line[i])
	{
		int j = 0;

		while (delimiters[j])
		{
			if (line[i] == delimiters[j])
				break;
			j++;
		}
		if (delimiters[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
