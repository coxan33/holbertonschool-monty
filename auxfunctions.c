#include "monty.h"
/**
 * number - is a number
 * @s: String
 *
 * Return: 1 or 0
 */
int number(char s[])
{
	int a = 0;

	if(s[0] == '-')
		s[0] = '0';
	for (a = 0; s[0]; a++)
		if (!isdigit(s[0]))
			return (0);
	return (1);
}

/**
 * op_push - Print all values
 * @stack: Linked List
 * @line_number: Number of Line
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *end = *stack;
	int num = 0;
	char *pointer = NULL;

	pointer = strtok(NULL, " \t\n");
	if (!pointer || number(pointer) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
num = atoi(pointer);
new = malloc(sizeof(stack_t));
if (!new)
	return;
new->n = num;
new->next = NULL;
if (end)
{
	while (end->next)
		end = end->next;
	new->prev = end;
	end->next = new;

}
else
{
	*stack = new;
	new->prev = NULL;
}
}

/**
 * op_pall - Prints Stack
 * @stack: Linked list.
 * @line_number: Number of line.
 */

void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

	while ((*stack)->prev != NULL)
		stack = (*stack)->prev;
	while (stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		stack = (*stack)->next;
	}
}
	/**
 * op_pint - Print Stack.
 * @stack: Linked list.
 * @line_number: Number of line.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer;

	if(!pointer)
	{
		fprintf(stderr, "L%u: cant pint stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	while (pointer->next)
		pointer = pointer->next;
	printf("%d\n", pointer->n);
}

/**
 * op_nop - it doesn't do anything
*/
void op_nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{

}