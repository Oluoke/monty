#include "monty.h"

/**
 * add_to_stack - Adds node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	first = *new_node;
	first->next = t_mp;
	t_mp->prev = first;
}

/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *t_mp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	t_mp = *stack;
	while (t_mp != NULL)
	{
		printf("%d\n", t_mp->n);
	t_mp = t_mp->next;
	}
}

/**
 * pop_top - Adds node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *t_mp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	t_mp = *stack;
	*stack = t_mp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(t_mp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		more_err(6, line_number);
	return;
	}

	printf("%d\n", (*stack)->n);
}
