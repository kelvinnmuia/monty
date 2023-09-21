#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define DELIMS " \t\n\a\b"
#define QUEUE 1
#define STACK 0

/*Global OPERATIONS CODE TOKENS*/
extern char **op_toks;

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

/* BYTECODE INTERPRETER FUNCTIONS */
void fr_stack(stack_t **stack);
int initl_stack(stack_t **stack);
int chck_mode(stack_t *stack);
void fr_toks(void);
unsigned int tokarr_len(void);
int rn_mn(FILE *mscrpt_fd);
void stp_tokerr(int error_code);

/*OPCODE HELPER FUNCTIONS */
void opc_push(stack_t **stack, unsigned int line_number);
void opc_pall(stack_t **stack, unsigned int line_number);
void opc_pop(stack_t **stack, unsigned int line_number);
void opc_pint(stack_t **stack, unsigned int line_number);
void opc_swap(stack_t **stack, unsigned int line_number);
void opc_add(stack_t **stack, unsigned int line_number);
void opc_nop(stack_t **stack, unsigned int line_number);
void opc_sub(stack_t **stack, unsigned int line_number);
void opc_div(stack_t **stack, unsigned int line_number);
void opc_mul(stack_t **stack, unsigned int line_number);
void opc_mod(stack_t **stack, unsigned int line_number);
void opc_pchar(stack_t **stack, unsigned int line_number);
void opc_pstr(stack_t **stack, unsigned int line_number);
void opc_rot1(stack_t **stack, unsigned int line_number);
void opc_rotr(stack_t **stack, unsigned int line_number);
void opc_stack(stack_t **stack, unsigned int line_number);
void opc_queue(stack_t **stack, unsigned int line_number);

/*MY STD LIBRARY FUNCTIONS*/
char **strtow(char *str, char *delims);
char *get_int(int n);

/*HELPER FUNCTIONS FOR ERRORS*/
int malc_err(void);
int filop_err(char *filename);
int usg_err(void);
int unopc_err(char *opcode, unsigned int line_number);
int nint_err(unsigned int line_number);
int pop_err(unsigned int line_number);
int pint_err(unsigned int line_number);
int smstack_err(unsigned int line_number, char *op);
int div_err(unsigned int line_number);
int pchar_err(unsigned int line_number, char *message);

#endif
