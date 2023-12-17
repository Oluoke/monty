#include "monty.h"

/**
 * print_char - Prints Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
	string_err(11, line_num);
	ascii = (*stack)->n;

	if (ascii < 0 || ascii > 127)
		string_err(10, line_num);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *t_mp;

	if (stack == NULL || *stack == NULL)

	{
		printf("\n");
		return;
	}
	t_mp = *stack;

	while (t_mp != NULL)
	{
		a = t_mp->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		t_mp = t_mp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t_mp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	t_mp = *stack;

	while (t_mp->next != NULL)

	t_mp = t_mp->next;
	t_mp->next = *stack;
	(*stack)->prev = t_mp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates last node of the stack to the top
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t_mp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	t_mp = *stack;

	while (t_mp->next != NULL)
		t_mp = t_mp->next;
	t_mp->next = *stack;
	t_mp->prev->next = NULL;
	t_mp->prev = NULL;
	(*stack)->prev = t_mp;
	(*stack) = t_mp;
}
