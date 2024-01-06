#include "monty.h"

/**
 * func_mul_nodes - multiply two elements inside a stack
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void func_mul_nodes(stack_t **stack_top, unsigned int l_num)
{
	int multp;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		func_err(8, l_num, "mul");

	(*stack_top) = (*stack_top)->next;
	multp = (*stack_top)->n * (*stack_top)->prev->n;
	(*stack_top)->n = multp;
	free((*stack_top)->prev);
	(*stack_top)->prev = NULL;
}


/**
 * func_mod_nodes - calculate the modulus of elements in a stack.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void func_mod_nodes(stack_t **stack_top, unsigned int l_num)
{
	int modls;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)

		func_err(8, l_num, "mod");


	if ((*stack_top)->n == 0)
		func_err(9, l_num);
	(*stack_top) = (*stack_top)->next;
	modls = (*stack_top)->n % (*stack_top)->prev->n;
	(*stack_top)->n = modls;
	free((*stack_top)->prev);
	(*stack_top)->prev = NULL;
}
