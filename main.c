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
	char *file_name1; // Declare variables at the beginning
	FILE *file1;
	int exit_status;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	char *file_name1 = argv[1];
	FILE *file1 = fopen(file_name1, "r");
	
	if (file1 == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", file_name1);
		exit(EXIT_FAILURE);
	}

	int exit_status = execute_monty(file1);

	fclose(file1);
	return (exit_status);
