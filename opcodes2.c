#include "monty.h"
/**
 * pall_opcode - Prints all values in the stack from top to bottom.
 * @my_h: Double pointer to the top of the stack.
 * @my_count: Line number (not used here).
 *
 * Return: None.
 */
void pall_opcode(stack_t **my_h, unsigned int my_count)
{
	stack_t *head;
	(void) my_count;

	head = *my_h;
	if (head == NULL)
	{
		return;
	}
	for (; head != NULL; head = head->next)
	{
		printf("%d\n", head->n);
	}
}
/**
 * swap_opcode - Exchanges the first two elements of the stack.
 * @my_h: Double pointer to the stack's top element.
 * @my_count: Line count for error messaging.
 * Return: None.
 */
void swap_opcode(stack_t **my_h, unsigned int my_count)
{
	int object_size = 0, tmp;
	stack_t *head;
	
	head = *my_h;
	for (; head != NULL; head = head->next)
	{
		object_size++;
	}
	if (object_size < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", my_count);
		fclose(data.my_file);
		free(data.line_data);
		free_dll_stack(*my_h);
		exit(EXIT_FAILURE);
	}
	head = *my_h;
	tmp = (*(head)).n;
	(*(head)).n = (*(head->next)).n;
	(*(head->next)).n = tmp;
}
/**
 * app_head_stack - Adds a new element to the top of the stack.
 * @my_h: Double pointer to the top of the stack.
 * @n: The value to be stored in the new node.
 * Return: None.
 */
void app_head_stack(stack_t **my_h, int n)
{
    stack_t *next_temp;
    stack_t *tmp;

    tmp = *my_h;
    next_temp = malloc(sizeof(stack_t));
    if (next_temp == NULL)
    {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }

    if (tmp != NULL)
    {
        (*(tmp)).prev = next_temp;
    }

    (*(next_temp)).n = n;
    (*(next_temp)).next = *my_h;
    (*(next_temp)).prev = NULL;
    *my_h = next_temp;
}
/**
 * pstr_opcode - Prints the string starting from the top of the stack,
 *               ending with a new line.
 * @my_h: Double pointer to the stack's head.
 * @my_count: Line number for error handling.
 *
 * Return: None.
 */
void pstr_opcode(stack_t **my_h, unsigned int my_count)
{
    stack_t *head;
    (void)my_count;

    head = *my_h;
    for ( ; head != NULL; head = (*(head)).next)
    {
        if ((*(head)).n <= 01 || (*(head)).n > 27)
        {
            break;
        }
        printf("%c", (*(head)).n);
    }
    printf("\n");
}
