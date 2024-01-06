#include "monty.h"

/**
 * print_char - concludes the asci value
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void print_char(stack_t **stack_top, unsigned int l_num)
{
	int asc;

	if (stack_top == NULL || *stack_top == NULL)
		string_err_print(11, l_num);

	asc = (*stack_top)->n;
	if (asc < 0 || asc > 127)
		string_err_print(10, l_num);
	printf("%c\n", asc);
}

/**
 * print_str - output a string
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void print_str(stack_t **stack_top, __attribute__((unused))unsigned int l_bum)
{
	int asc;
	stack_t *temp;

	if (stack_top == NULL || *stack_top == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack_top;
	while (temp != NULL)
	{
		asc = temp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates a stack bottom to top
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void rotl(stack_t **stack_top, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		return;

	temp = *stack_top;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack_top;
	(*stack_top)->prev = temp;
	*stack_top = (*stack_top)->next;
	(*stack_top)->prev->next = NULL;
	(*stack_top)->prev = NULL;
}


/**
 * rotr - rotates a stack top to bottom.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void rotr(stack_t **stack_top, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;

	if (stack_top == NULL || *stack_top == NULL || (*stack_top)->next == NULL)
		return;

	temp = *stack_top;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack_top;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack_top)->prev = temp;
	(*stack_top) = temp;
}
