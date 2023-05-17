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

#include "monty.h"

/**
 * op_swap - prints the value at the top of the stack.
 * @stack: Linked list
 * @line_number: NUmber line
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int copy;
	stack_t *pointer;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	while (pointer->next)
		pointer = pointer->next;
	if (!pointer->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	copy = pointer->n;
	pointer->n = pointer->prev->n;
	pointer->prev->n = copy;
}
/**
 * op_add - prints the value at the top of the stack.
 * @stack: Linked list
 * @line_number: Number line
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;

	if (!*stack || !pointer->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (pointer->next->next)
		pointer = pointer->next;
	pointer->n += pointer->next->n;
	op_pop(stack, line_number);
}
