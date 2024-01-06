#include "monty.h"

/**
 * nop - function that do nothing.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void nop(stack_t **stack_top, unsigned int l_num)
{
	(void)stack_top;
	(void)l_num;
}


/**
 * swap_nodes_func - swaps elements inside a stack
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void swap_nodes_func(stack_t **stack_top, unsigned int l_num)
{
	stack_t *temp;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		func_err(8, l_num, "swap");
	temp = (*stack_top)->next;
	(*stack_top)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack_top;
	temp->next = *stack_top;
	(*stack_top)->prev = temp;
	temp->prev = NULL;
	*stack_top = temp;
}

/**
 * func_add_nodes - adds elements inside a stack
 * @stack_top: pointer to node top head
 * @l_num: determines the line numbe
 */
void func_add_nodes(stack_t **stack_top, unsigned int l_num)
{
	int sum;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		func_err(8, l_num, "add");

	(*stack_top) = (*stack_top)->next;
	sum = (*stack_top)->n + (*stack_top)->prev->n;
	(*stack_top)->n = sum;
	free((*stack_top)->prev);
	(*stack_top)->prev = NULL;
}


/**
 * func_sub_nodes - subtracts elements inside a stack
 * @stack_top: pointer to node top head
 * @l_num: determines the line numbe
 */
void func_sub_nodes(stack_t **stack_top, unsigned int l_num)
{
	int sub;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)

		func_err(8, l_num, "sub");


	(*stack_top) = (*stack_top)->next;
	sub = (*stack_top)->n - (*stack_top)->prev->n;
	(*stack_top)->n = sub;
	free((*stack_top)->prev);
	(*stack_top)->prev = NULL;
}


/**
 * func_div_nodes - divides elements inside a stack
 * @stack_top: pointer to node top head
 * @l_num: determines the line numbe
 */
void func_div_nodes(stack_t **stack_top, unsigned int l_num)
{
	int divd;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		func_err(8, l_num, "div");

	if ((*stack_top)->n == 0)
		func_err(9, l_num);
	(*stack_top) = (*stack_top)->next;
	divd = (*stack_top)->n / (*stack_top)->prev->n;
	(*stack_top)->n = divd;
	free((*stack_top)->prev);
	(*stack_top)->prev = NULL;
}
