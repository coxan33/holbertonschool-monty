#include "monty.h"

/**
 * free_stack - free all.
 * @stack: Doubly linked list to be free.
 */
void free_stack(stack_t *stack)
{
	stack_t *to_be_free;
	stack_t *temp = NULL;

	to_be_free = stack;
	while (to_be_free)
	{
		temp = to_be_free->next;
		free(to_be_free);
		to_be_free = temp;
	}
}
