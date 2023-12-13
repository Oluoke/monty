#include "monty.h"

/**
 * mod_top_two_elements - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void mod_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *active = *head;
	int len = 0, result;

	while (active)
	{
		active = active->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	active = *head;

	if (active->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	result = active->next->n % active->n;
	active->next->n = result;
	*head = active->next;
	free(active);
}
