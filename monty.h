#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syst/types.h>
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

extern ** inst_toks1

void initStack(Stack_t **stack);
void freeStack(Stack_t **stack);
int check_list_mode(stack_t *stack);
void execute_monty(const char *instruction, Stack *stack);
void set_error1(int error_code)
char **tokenizeString(char *input, char *delimiters)
int isDelimiter(char character, char *delimiters)
int getWordLength(char *input, char *delimiters)
int countWords(char *input, char *delimiters)
char *getNextWord(char *input, char *delimiters)
void (*get_op_function(char *opcode))(stack_t**, unsigned int)
int execute_monty(FILE *file1)
void releaseTokens(void)
unsigned int countTokens(void)
int isLineEmpty(char *line, char *delimiters)

