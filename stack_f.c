#include "monty.h"

/**
 * nop - does nothing
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * swap_nodes - Swaps top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *t_mp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "swap");
	t_mp = (*stack)->next;
	(*stack)->next = t_mp->next;
	if (t_mp->next != NULL)
		t_mp->next->prev = *stack;
	t_mp->next = *stack;
	(*stack)->prev = t_mp;
	t_mp->prev = NULL;
	*stack = t_mp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_num)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Adds top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_num)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_num, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_num)
{
	int d;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "div");

	if ((*stack)->n == 0)
		more_err(9, line_num);
	(*stack) = (*stack)->next;
	d = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = d;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
