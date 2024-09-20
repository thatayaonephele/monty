#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

data_t data = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for Monty code interpreter
 * @argc: Number of arguments passed
 * @argv: Array of arguments containing file name
 *
 * Description: Opens a Monty script file, reads each line,
 * and processes the commands to manipulate a stack. This interpreter
 * reads one line at a time and passes the content for execution.
 *
 * Return: 0 on success, exits with failure if errors occur
 */
int main(int argc, char *argv[])
{
	char *line_data;
	FILE *my_file;
	size_t object_size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int my_count = 0;

	/* Argument count must be exactly 2 (program name and file name) */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty bytecode file */
	my_file = fopen(argv[1], "r");
	data.my_file = my_file;
	if (!my_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read each line from the file and execute its content */
	for (; read_line > 0; my_count++)
	{
		line_data = NULL;
		read_line = getline(&line_data, &object_size, my_file);
		data.line_data = line_data;

		if (read_line > 0)
		{
			run_cmd(line_data, &stack, my_count, my_file);
		}
		free(line_data);
	}

	/* Clean up and close the file */
	free_dll_stack(stack);
	fclose(my_file);

	return (0);
}
