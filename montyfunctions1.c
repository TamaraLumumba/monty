/*
 * File: montyfunction1.c
 * Auth: Tamara Lumumba
 */

#include "monty.h"


/**
 * monty_push1 - Appends a value to a linked list implementing a stack_t.
 * @stack: Pointer to the head node of the stack_t linked list.
 * @line_number: The current line number being executed in the Monty bytecodes file.
 */
void monty_push1(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_error1(malloc_error());
		return;
	}
	if (inst_toks1[1] == NULL)
	{
		set_error1(no_int_error(line_number));
		return;
	}
	for (i = 0; inst_toks1[1][i]; i++)
	{
		if (inst_toks1[1][i] == '-' && i == 0)
			continue;
		if (inst_toks1[1][i] < '0' || inst_toks1[1][i] > '9')
		{
			set_error1(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(inst_toks1[1]);

	if (check_list_mode(*stack) == STACK)
	{
		current = (*stack)->next;
		new->prev = *stack;
		new->next = current;
		if (current)
			current->prev = new;
		(*stack)->next = new;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		new->prev = current;
		new->next = NULL;
		current->next = new;
	}
}

/**
 * monty_pall1 - Outputs the elements stored in a stack_t linked list.
 * @stack: Pointer to the top node of the stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pall1(stack_t **stack, unsigned int line_number)
{
	Stack_t *current = (*stack)->next;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}


/**
 * monty_pint1 - Displays the top value of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number within the Monty bytecodes file.
*/
void monty_pint1(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_error1(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop1 - Deletes the top element of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecodes file.
 */
void monty_pop1(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_error1(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap1 - Exchanges the positions of the top two elements in a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number within the Monty bytecodes file.
 */
void monty_swap1(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_error1(short_stack_error(line_number, "swap"));
		return;
	}

	current = (*stack)->next->next;
	(*stack)->next->next = current->next;
	(*stack)->next->prev = current;
	if (current->next)
		current->next->prev = (*stack)->next;
	current->next = (*stack)->next;
	current->prev = *stack;
	(*stack)->next = current;
}
