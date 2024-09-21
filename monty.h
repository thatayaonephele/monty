#ifndef TADEM_H
#define TADEM_H


#define _GNU_SOURCE
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

/**
 * struct data_s - A data struct housing the args, my_file & line_data
 * @arg: The argument value parameter
 * @my_file: pointer to monty file
 * @line_data: line content
 * @last_in_first_in: flag change stack <-> queue
 *
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *my_file;
	char *line_data;
	int last_in_first_in;
} data_t;
extern data_t data;

/* Function declarations for stack/queue operations */
int run_cmd(char *line_data, stack_t **my_h, unsigned int my_count, FILE *my_file);
void free_dll_stack(stack_t *my_h);
void app_head_stack(stack_t **my_h, int n);
void app_tail_queue(stack_t **my_h, int n);
void set_mode_to_queue(stack_t **my_h, unsigned int my_count);
void set_mode_to_lifo(stack_t **my_h, unsigned int my_count);

/* Opcode-related functions */
void push_opcode(stack_t **my_h, unsigned int number);
void pall_opcode(stack_t **my_h, unsigned int number);
void pint_opcode(stack_t **my_h, unsigned int number);
void pop_opcode(stack_t **my_h, unsigned int my_count);
void swap_opcode(stack_t **my_h, unsigned int my_count);
void add_opcode(stack_t **my_h, unsigned int my_count);
void nop_opcode(stack_t **my_h, unsigned int my_count);
void sub_opcode(stack_t **my_h, unsigned int my_count);
void div_opcode(stack_t **my_h, unsigned int my_count);
void mul_opcode(stack_t **my_h, unsigned int my_count);
void mod_opcode(stack_t **my_h, unsigned int my_count);
void pchar_opcode(stack_t **my_h, unsigned int my_count);
void pstr_opcode(stack_t **my_h, unsigned int my_count);
void rotl_opcode(stack_t **my_h, unsigned int my_count);
void rotr_opcode(stack_t **my_h, __attribute__((unused)) unsigned int my_count);

#endif /* TADEM_H */
