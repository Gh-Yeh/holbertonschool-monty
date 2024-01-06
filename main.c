#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	func_open_file(argv[1]);
	func_free_nodes();
	return (0);
}

/**
 * func_create_node - Creates a node.
 * @n: input of the node.
 * Return: pointer to a node if success.
 */
stack_t *func_create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		err_han(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
 * func_free_nodes - used to free a node
 */
void func_free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * push_to_queue - Adds a node to the queue.
 * @n_node: Pointer to the new node.
 * @l_num: number of op code
 */

void push_to_queue(stack_t **n_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *n_node;
	(*n_node)->prev = temp;

}
