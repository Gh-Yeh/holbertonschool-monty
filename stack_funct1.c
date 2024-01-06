#include "monty.h"


/**
 * push_to_stack - push nodes to stack storage.
 * @new_node: new node pointer.
 * @ln: determines the line number
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * print_stack_func - print nodes from stack storage.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void print_stack_func(stack_t **stack_top, unsigned int l_num)
{
	stack_t *temp;

	(void) l_num;
	if (stack_top == NULL)
		exit(EXIT_FAILURE);
	temp = *stack_top;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_from_top - remove nodes from stack storage.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void pop_from_top(stack_t **stack_top, unsigned int l_num)
{
	stack_t *temp;

	if (stack_top == NULL || *stack_top == NULL)
		func_err(7, l_num);

	temp = *stack_top;
	*stack_top = temp->next;
	if (*stack_top != NULL)
		(*stack_top)->prev = NULL;
	free(temp);
}

/**
 * print_from_top - print nodes from the top stack storage.
 * @stack_top: pointer to node top head
 * @l_num: determines the line number
 */
void print_from_top(stack_t **stack_top, unsigned int l_num)
{
	if (stack_top == NULL || *stack_top == NULL)
		func_err(6, l_num);
	printf("%d\n", (*stack_top)->n);
}
