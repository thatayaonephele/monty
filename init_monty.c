#include "monty.h"

/**
 * run_cmd - Function that executes the opcode from the Monty bytecode file.
 * @stack: Double pointer to the head of the stack (linked list).
 * @my_count: Line number in the Monty script (used for error messages).
 * @my_file: File stream of the Monty bytecode file.
 * @line_data: Line content from the Monty script.
 *
 * Description: This function takes the current line of Monty bytecode,
 * extracts the opcode, and matches it with the correct function to execute.
 * If the opcode is unknown, it exits with an error.
 *
 * Return: 0 on success, exits with failure if an unknown instruction is found.
 */
int run_cmd(char *line_data, stack_t **stack, unsigned int my_count,
		FILE *my_file)
{
	instruction_t opst[] = {
		{"push", push_opcode}, {"pall", pall_opcode}, {"pint", pint_opcode},
		{"pop", pop_opcode}, {"swap", swap_opcode}, {"add", f_add},
		{"nop", f_nop}, {"sub", sub_opcode}, {"div", div_opcode},
		{"mul", mul_opcode}, {"mod", mod_opcode}, {"pchar", pchar_opcode},
		{"pstr", pstr_opcode}, {"rotl", rotl_opcode}, {"rotr", rotr_opcode},
		{"queue", set_mode_to_queue}, {"stack", set_mode_to_lifo}, {NULL, NULL}
	};

	char *my_op;
	unsigned int x;

	/* Tokenize the line content to get the opcode */
	my_op = strtok(line_data, " \n\t");
	if (my_op && my_op[0] == '#') /* Ignore comments starting with '#' */
		return (0);

	/* Get the argument for push opcode (if any) */
	data.arg = strtok(NULL, " \n\t");

	for (x = 0; opst[x].opcode && my_op; x++)
	{
		if (strcmp(my_op, opst[x].opcode) == 0)
		{
			opst[x].f(stack, my_count);
			return (0);
		}
	}

	/* If no valid opcode is found, print an error message and exit */
	if (my_op && opst[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", my_count, my_op);
		fclose(my_file);
		free(line_data);
		free_dll_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
/**
 * rotl_opcode - Function that rotates the stack to the top.
 * @my_h: Double pointer to the head of the stack.
 * @my_count: Line count (unused).
 *
 * Return: Nothing.
 */
void rotl_opcode(stack_t **my_h, unsigned int my_count __attribute__((unused)))
{
	stack_t *copy, *temp = *my_h;

	if ((*(temp).next) == NULL || *my_h == NULL)
	{
		return;
	}
	copy = (*(temp).next);
	(*(copy).prev) = NULL;
	for (; (*(temp).next) != NULL; temp = (*(temp).next))
	{
		/* No body required, as we are iterating until the end */
	}
	(*(temp).next) = *my_h;
	(*(*my_h)).next = NULL;
	(*(*my_h)).prev = temp;
	*my_h = copy;
}
