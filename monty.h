#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define STACK 0
#define QUEUE 1
#define delimiters " \n\t\a\b"


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char ** op_toks1;

void initStack(stack_t **stack);
void freeStack(stack_t **stack);
int check_list_mode(stack_t *stack);
void set_error1(int error_code);
void (*get_op_function(char *opcode))(stack_t**, unsigned int);
int execute_monty(FILE *file1);
void releaseTokens(void);
unsigned int countTokens(void);

void monty_push1(stack_t **stack, unsigned int line_number);
void monty_pall1(stack_t **stack, unsigned int line_number);
void monty_pint1(stack_t **stack, unsigned int line_number);
void monty_pop1(stack_t **stack, unsigned int line_number);
void monty_swap1(stack_t **stack, unsigned int line_number);

int malloc_error(void);
int unknown_op_error(char *opcode, unsigned int line_number);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

#endif
