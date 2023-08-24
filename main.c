/*
 * File: main.c
 * Auth: Tamara Lumumba
 */


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

	if (file1 == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	int exit_status = execute_Monty(file1);

	fclose(file1);
	return (exit_status);
