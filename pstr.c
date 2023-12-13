#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

