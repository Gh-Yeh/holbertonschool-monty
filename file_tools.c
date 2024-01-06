#include "monty.h"

/**
 * func_open_file - used to open a file
 * @file_name_path: the path file name
 * Return: void
 */

void func_open_file(char *file_name_path)
{
	FILE *fd = fopen(file_name_path, "r");

	if (file_name_path == NULL || fd == NULL)
		err_han(2, file_name_path);

	func_read_file(fd);
	fclose(fd);
}


/**
 * func_read_file - to reads from a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void func_read_file(FILE *fd)
{
	int l_num, format = 0;
	char *buf = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&buf, &len, fd) != -1; l_num++)
	{
		format = func_parse_line(buf, l_num, format);
	}
	free(buf);
}


/**
 * func_parse_line - parse a line to split tokens
 * @buf: line inside a file
 * @l_numb: the number of a line
 * @format: determine which format to use
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int func_parse_line(char *buf, int l_numb, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buf == NULL)
		err_han(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, l_numb, format);
	return (format);
}

/**
 * find_function - conclude the right op to use
 * @opcode: opcode
 * @value_op: argument of opcode
 * @format: determine which format to use
 * @ln: line number
 * Return: void
 */
void find_function(char *opcode, char *value_op, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", print_stack_func},
		{"pint", print_from_top},
		{"pop", pop_from_top},
		{"nop", nop},
		{"swap", swap_nodes_func},
		{"add", func_add_nodes},
		{"sub", func_sub_nodes},
		{"div", func_div_nodes},
		{"mul", func_mul_nodes},
		{"mod", func_mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_function(func_list[i].f, opcode, value_op, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err_han(3, ln, opcode);
}


/**
 * call_function - determine the function call
 * @p_func: function pointer call
 * @op: concluding the opcode
 * @value: determining the value
 * @ln: number line
 * @format: determine which format to use
 */
void call_function(op_func p_func, char *op, char *value, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err_han(5, ln);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err_han(5, ln);
		}
		node = func_create_node(atoi(value) * flag);
		if (format == 0)
			p_func(&node, ln);
		if (format == 1)
			push_to_queue(&node, ln);
	}
	else
		p_func(&head, ln);
}
