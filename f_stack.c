#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (current != NULL)
	{
		stack_t *next_node = current->next;

		free(current);
		current = next_node;
	}
}

