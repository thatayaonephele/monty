#include "monty.h"
/**
 * set_mode_to_queue - This function sets the mode to operate as a queue.
 * @my_h: Double pointer to the head of the stack (not used).
 * @my_count: Line number for error reporting (not used).
 *
 * Return: This function does not return a value.
 */
void set_mode_to_queue(stack_t **my_h, unsigned int my_count)
{
	(void)my_h;
	(void)my_count;
	data.last_in_first_in = 1;
}

/**
 * app_tail_queue - This function adds a new node to the end of the queue.
 * @my_h: Double pointer to the head of the queue.
 * @n: The value that will be added to the queue.
 *
 * Return: This function does not return a value.
 */
void app_tail_queue(stack_t **my_h, int n)
{
	stack_t *latest_node;
	stack_t *tmp;

	latest_node = malloc(sizeof(stack_t));
	if (latest_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	latest_node->n = n;
	latest_node->next = NULL;
	tmp = *my_h;
	if (tmp == NULL)
	{
		*my_h = latest_node;
		latest_node->prev = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = latest_node;
		latest_node->prev = tmp;
	}
}
