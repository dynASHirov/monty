#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exe_cute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruc_tion_t opst[] = {
				{"push", f_push}, {"pall", _f_pall}, {"pint", _f_pint},
				{"pop", _f_pop},
				{"swap", _f_swap},
				{"add", f_addd},
				{"nop", _f_nop},
				{"sub", _f_sub},
				{"div", _f_div},
				{"mul", _f_mul},
				{"mod", _f_mod},
				{"pchar", _f_pchar},
				{"pstr", _f_pstr},
				{"rotl", _f_rotl},
				{"rotr", _f_rotr},
				{"queue", _f_queue},
				{"stack", _f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}