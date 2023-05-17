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

/**
 * op_pop - deletes the current top of the stack.
 * @stack: Linked list.
 * @line_number: Number line.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *delete;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!node->next)
	{
		free(node);
		*stack = NULL;
	}
	else
		while (node->next->next)
			node = node->next;
	delete = node->next;
	node->next = NULL;
	free(delete);
}
