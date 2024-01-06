#include "monty.h"

/**
 * err_han - handles the erros based on switch cases
 * @err_cases: cases that hold errors
 */
void err_han(int err_cases, ...)
{
	va_list ag;
	char *op_code;
	int l_num;

	va_start(ag, err_cases);
	switch (err_cases)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op_code = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * func_err - handles the erros based on switch cases
 * @err_cases: cases that hold errors
 */
void func_err(int err_cases, ...)
{
	va_list ag;
	char *op_code;
	int l_num;

	va_start(ag, err_cases);
	switch (err_cases)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op_code = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err_print - handles the erros based on switch cases
 * @err_cases: cases that hold errors
 */
void string_err_print(int err_cases, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, err_cases);
	l_num = va_arg(ag, int);
	switch (err_cases)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}
