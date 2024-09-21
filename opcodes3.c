#include "monty.h"
/**
 * pop_opcode - Removes the top element from the stack.
 * @my_h: Double pointer to the top of the stack.
 * @my_count: Line number used for error messages.
 * Description: If the stack is empty, an error message is printed
 * and the program exits. If not, it removes the topmost element
 * from the stack
 * Return: Nothing (void function).
 */
void pop_opcode(stack_t **my_h, unsigned int my_count)
{
	stack_t *head;

	if (*my_h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", my_count);
		fclose(data->my_file);
		free(data->line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}
	head = *my_h;
	*my_h = head.next;
	free(head);
}
/**
 * pint_opcode - Prints the top element of the stack.
 * @my_h: Double pointer to the top of the stack.
 * @my_count: Line number for error reporting.
 * Description: If the stack is empty, the function prints an error message
 * and exits program. Otherwise, it prints the value at the top of the stack.
 * Return: Nothing (void function).
 */
void pint_opcode(stack_t **my_h, unsigned int my_count)
{
	if (*my_h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", my_count);
		fclose(data->my_file);
		free(data->line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", *(my_h).n);
}
/**
 * nop_opcode - A function that performs no action.
 * @my_h: Double pointer to the top of the stack (unused).
 * @my_count: Line number (unused).
 * Description: This function is intentionally left empty and doesn't alter
 * the stack or perform any operations. It serves as a placeholder for
 * 'nop' opcode, which does nothing.
 * Return: Nothing (void function).
 */
void nop_opcode(stack_t **my_h, unsigned int my_count)
{
	(void) my_count;
	(void) my_h;
}
/**
 * sub_opcode - Subtracts the top two elements of the stack.
 * @my_h: Double pointer to the head of the stack.
 * @my_count: Line count for error reporting.
 *
 * Description: This function checks if there are at least two elements in
 * the stack, subtracts the top element from the second, and updates the stack.
 * If the stack has fewer than two elements, an error is reported.
 */
void sub_opcode(stack_t **my_h, unsigned int my_count)
{
	int argument_cnt, est_diff;
	stack_t *tmp;

	/* Count the number of elements in the stack */
	tmp = *my_h;
	argument_cnt = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		argument_cnt++;
	}
	if (argument_cnt < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}
	tmp = *my_h;
	est_diff = (tmp->next)->n - tmp->n;
	(tmp->next)->n = est_diff;
	*my_h = tmp->next;
	free(tmp);
}
