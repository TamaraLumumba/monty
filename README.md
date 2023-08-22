0x19. C - Stacks, Queues - LIFO, FIFO

ABOUT 
In this project, we were able to create a basic interpreter for Monty ByteCodes. The interpreter reads a file containing bytecode and carries out the corresponding bytecode instructions.

THE MONTY LANGUAGE
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

MONTY FILES
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

GENERAL KNOWLEDGE REQUIREMENTS
LIFO and FIFO
Stack Definition and Usage
Queue Definition and Usage:
Common Implementations:
Common Use Cases:
Proper Global Variable Use:

PROJECT GUIDELINES
Allowed editors: vi, vim, emacs
Files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
Files should end with a new line
A README.md file, at the root of the folder is mandatory
Your code should use the Betty style.
Use a maximum of one global variable.
Only 5 functions per file.
You are allowed to use the C standard library.
The prototypes of all your functions should be included in your header file called monty.h
Header files should be include guarded.
Do the tasks in the order shown in the project.

DATA STRUCTURES
Use the following data structures for this project. 
Don’t forget to include them in your header file.

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

Compilation & Output
Code will be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Any output must be printed on stdout
Any error message must be printed on stderr

STEPS AND PROCEDURES
0. push, pall
	We implement the push and pall opcodes
	This is an opcode that pushes an element to the stack.
	This is an opcode that prints all the values on the stack, starting from the top of the stack.

1. pint
	We implement the pint opcode
	This is an opcode that prints the value at the top of the stack, followed by a new line.

2. pop
	We implemen the pop opcode
	This is an opcode that removes the top element of the stack

3. swap
	We implement the swap opcode
	This is an opcode that swaps the top two elements of the stack.

4. add
	We implement the add opcode.
	This is an opcode that adds the top two elements of the stack.

5. nop
	We implement the nop opcode.
	This is an opcode that doesn’t do anything.
