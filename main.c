#include "monty.h"

/**
 * getopc - Function
 * @opc: Code name
 * Return: 0
 */

void (*getopc(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"nop", op_nop},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opc, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (instructions[i].f);
}
/**
 * main - monty
 * @argc: Size
 * @argv: Array
 * Return: 0
 */

int main(int argc, char **argv)
{
        FILE *fp = NULL;
        char *buffer = NULL; 
	char *opc = NULL;
        int cont = 0;
        size_t size = 0;
        stack_t *stack = NULL;
        void(*f)(stack_t **stack, unsigned int line_num);

        if (argc != 2)
                fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
        fp = fopen(argv[1], "r");
        if (!fp)
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
        while (getline(&buffer, &size, fp) != -1)
        {
                cont++;
                opc = strtok(buffer, " \t\n");
                if (!opc || strcmp(opc, "nop") == 0 || strcmp(opc, "\n") == 0)
                        continue;
                f = getopc(opc);
                if (!f)
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", cont, opc);
                        exit(EXIT_FAILURE);
                }
                f(&stack, cont);              
        }
        free(buffer);
        fclose(fp);
        return (0);
}
