#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Pointer to the stack head.
 * @counter: Unused parameter (line number).
 * Return: No return.
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return; /* No rotation needed for an empty stack or a single node. */
	}

	while (copy->next)
	{
		copy = copy->next;
	}

	/* Perform the rotation */
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

