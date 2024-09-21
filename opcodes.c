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
/**
 * mod_opcode - Computes the remainder of the division of the 2ndtop element
 * by the top element of the stack.
 * @my_h: Double pointer to the head of the stack.
 * @my_count: Line count for error reporting.
 *
 * of the stack is divided by the top element. If the stack has fewer than two
 * elements, or if the top element is zero, an error is reported.
 */
void mod_opcode(stack_t **my_h, unsigned int my_count)
{
	int tmp, length = 0;
	stack_t *head;

	/* Count the number of elements in the stack */
	for (head = *my_h; head != NULL; head = head->next)
		length++;

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}

	head = *my_h;
	if ((*(head)).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}

	tmp = (*(head->next)).n % (*(head)).n;
	(*(head->next)).n = tmp;
	*my_h = (*(head)).next;
	free(head);
}
/**
 * div_opcode - Divides the top two elements of the stack.
 * @my_h: Double pointer to the head of the stack.
 * @my_count: Line count for error reporting.
 *
 * by the top element. If there are fewer than two elements, or if the top
 * element is zero, an error is reported.
 */
void div_opcode(stack_t **my_h, unsigned int my_count)
{

	int tmp, length = 0;
	stack_t *head;

	/* Count the number of elements in the stack */
	for (head = *my_h; head != NULL; head = head->next)
		length++;

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}

	head = *my_h;
	if ((*(head)).n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}

	tmp = (*(head->next)).n / (*(head)).n;
	(*(head->next)).n = tmp;
	*my_h = (*(head)).next;
	free(head);
}
/**
 * mul_opcode - Multiplies the top two elements of the stack.
 * @my_h: Double pointer to the head of the stack.
 * @my_count: Line count for error reporting.
 *
 * & updates the stack. If there are < 2 elements, an error is reported.
 */
void mul_opcode(stack_t **my_h, unsigned int my_count)
{
	stack_t *head;
	int tmp, length = 0;

	/* Count the number of elements in the stack */
	for (head = *my_h; head != NULL; head = head->next)
		length++;

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}

	head = *my_h;
	tmp = (*(head->next)).n * (*(head)).n;
	(*(head->next)).n = tmp;
	*my_h = (*(head)).next;
	free(head);
}
