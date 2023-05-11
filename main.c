#include "monty.h"

/**
 * main - monty
 * @argc: Size
 * @argv: Array
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL},
	};
}