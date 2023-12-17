#include "monty.h"
stack_t *first = NULL;

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0
*/
int main(int argc, char *argv[])
{
	if (argc != 2)

	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates node.
 * @n: Number to go into the node.
 * Return: a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
		err(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * free_nodes - Frees the nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *t_mp;

	if (first == NULL)
	return;

	for (t_mp = first; t_mp != NULL;)
	{
		first = first->next;
		free(t_mp);
		t_mp = first;

	}
}

/**
 * add_to_queue - Add nodes to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *t_mp;

	if (new_node == NULL || *new_node == NULL)
	exit(EXIT_FAILURE);

	if (first == NULL)
	{
	first = *new_node;
	return;
	}
	t_mp = first;
	while (t_mp->next != NULL)
	t_mp = t_mp->next;

	t_mp->next = *new_node;
	(*new_node)->prev = t_mp;
}
