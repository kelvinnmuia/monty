#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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
 * struct bs_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @swt_mode: flag to switch stack <-> queue
 * Description: contains core parameters used by the program
 */
typedef struct bs_s
{
	char *arg;
	FILE *file;
	char *content;
	int swt_mode;
}  bs_t;
extern bs_t bs;
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
/*--Core Interpreter Functions--*/
void inptr_addnode(stack_t **head, int n);
void inptr_addqueue(stack_t **head, int n);
void inptr_free_stack(stack_t *head);
int run_opc(char *content, stack_t **stack, unsigned int line_number, FILE *file);
/*--Opcode Functions--*/
void opc_add(stack_t **head, unsigned int line_number);
void opc_sub(stack_t **head, unsigned int line_number);
void opc_mul(stack_t **head, unsigned int line_number);
void opc_div(stack_t **head, unsigned int line_number);
void opc_mod(stack_t **head, unsigned int line_number);
void opc_pall(stack_t **head, unsigned int line_number);
void opc_pint(stack_t **head, unsigned int line_number);
void opc_pop(stack_t **head, unsigned int line_number);
void opc_pchar(stack_t **head, unsigned int line_number);
void opc_pstr(stack_t **head, unsigned int line_number);
void opc_nop(stack_t **head, unsigned int line_number);
void opc_queue(stack_t **head, unsigned int line_number);
void opc_stack(stack_t **head, unsigned int line_number);
void opc_swap(stack_t **head, unsigned int line_number);
void opc_rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number);
void opc_rotr(stack_t **head, __attribute__((unused)) unsigned int line_number);
void opc_push(stack_t **head, unsigned int line_number);
/*--Standard Library Functions--*/
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char  *clean_line(char *content);
ssize_t getstdin(char **lineptr, int file);
#endif
