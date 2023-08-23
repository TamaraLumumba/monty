#include "monty.h"

/**
 * main - entry point for the monty code interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: 0 on succesful execution
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	char *file_name1 = argv[1];
	FILE *file1 = fopen(file_name1, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	char *linebuffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead;

	int linecounter = 0;
	stack montystack;

	initStack(&montystack); /* initializing the stack*/

	while ((byteRead = getline(&lineBuffer, &bufferSize, file1)) != -1)
	{
		lineCounter++;
		if (byteRead > 0 && linebuffer[bytesRead - 1] == '\n')
		{
			lineBuffer[bytesRead - 1] = '\0';
		}

		executeMontyInstruction(lineBuffer, &montyStack);
	}

	fclose(inputFile);
	free(lineBuffer);
	freeStack(&montystack);
