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
 * op_push
 * @stack: Linked List
 * @line_number: Number of Line
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *end = *stack;
	int num = 0;
	char *
}

