/*
 * File: stack1.c
 * Auth: Tamara Lumumba
 */

#include "monty.h"

/**
 * initStack - Creates and initializes a new stack_t instance with initial
 *             stack and ending queue nodes.
 * @stack: A pointer to a stack_t pointer that will store the new instance.
 *
 * Returns: If successful - Nothing.
 *          If memory allocation fails - Calls malloc_error() function.
 */
void initStack(stack_t **stack)
{
	stack_t *newStack = malloc(sizeof(stack_t));

	if (newStack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	newStack->n = STACK;
	newStack->prev = NULL;
	newStack->next = NULL;

	*stack = newStack;
}

/**
 * freeStack - Deallocates a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 *
 * Notes: This function releases the memory used by each element in the stack,
 *        starting from the provided pointer and working through the list.
 */
void freeStack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}

	*stack = NULL;
}

/**
 * check_list_mode - Determines the operational mode (stack/queue)
 *                   of a stack_t linked list.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If stack_t operates in stack mode - STACK (0).
 *          If stack_t operates in queue mode - QUEUE (1).
 *          Otherwise - 2.
 */
int check_list_mode(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		if (current->n == STACK)
		{
			return (STACK);
		} else if (current->n == QUEUE)
		{
			return (QUEUE);
		}
		current = current->next;
	}

	return (2);
}
