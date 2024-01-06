#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void func_open_file(char *file_name);
int func_parse_line(char *buffer, int line_number, int format);
void func_read_file(FILE *);
void find_function(char *, char *, int, int);

stack_t *func_create_node(int num);
void func_free_nodes(void);
void print_stack_func(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void push_to_queue(stack_t **, unsigned int);
void call_function(op_func, char *, char *, int, int);

void print_from_top(stack_t **, unsigned int);
void pop_from_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes_func(stack_t **, unsigned int);

void func_add_nodes(stack_t **, unsigned int);
void func_sub_nodes(stack_t **, unsigned int);
void func_div_nodes(stack_t **, unsigned int);
void func_mul_nodes(stack_t **, unsigned int);
void func_mod_nodes(stack_t **, unsigned int);

void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

void err_han(int error_code, ...);
void func_err(int error_code, ...);
void string_err_print(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
