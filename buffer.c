#include "monty.h"

/**
 * free_dll_stack - Frees a doubly linked list (stack).
 * @my_h: Pointer to the first element of the stack (the head).
 *
 * Description: This function traverses the stack, freeing each node
 * one at a time. It stops when the end of the stack (NULL) is reached.
 *
 * Return: None.
 */
void free_dll_stack(stack_t *my_h)
{
	stack_t *temp;

	for (temp = my_h; my_h != NULL; my_h = temp)
	{
		temp = my_h->next;
		free(my_h);
	}
}

/**
 * set_mode_to_lifo - Set stack behavior / LIFO (Last In, First Out).
 * @my_h: Double pointer to the top of the stack.
 * @my_count: Line number in the bytecode file (for error messages).
 *
 * Description: This function modifies the mode in which the stack operates.
 * In this case,set the behavior to stack (LIFO) by changing `data.lifi` flag
 * The function does not perform any other operation.
 *
 * Return: None.
 */
void set_mode_to_lifo(stack_t **my_h, unsigned int my_count)
{
	(void)my_h; /* Head is not used in this function */
	(void)my_count; /* Counter is not used in this function */

	/* Set the mode to LIFO (stack behavior) */
	data.last_in_first_in = 0;
}
