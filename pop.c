#include "monty.h"

/**
 * f_pop - Removes the top element of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *active;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	active = *head;
	*head = active->next;
	free(active);
}

