#include "monty.h"

/**
 * open_file - opens a file
 * @f_name: the file namepath
 * Return: void
 */
void open_file(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
	{
	err(2, f_name);
	return;
	}

	read_file(fd);

	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void read_file(FILE *fd)
{
	int line_num = 1;
	int format = 0;
	char *buf = NULL;
	size_t length = 0;

	while (getline(&buf, &length, fd) != -1)
	{
	format = parse_line(buf, line_num, format);
	line_num++;
	}

	free(buf);
}

/**
 * parse_line - Separates the lines into tokens to determine
 * which function to call
 * @buf: line from the file
 * @line_number: line number
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buf, int line_number, int format)
{
	char *opcode, *val;
	const char *delimeter = "\n ";

	if (buf == NULL)
		err(4);

	opcode = strtok(buf, delimeter);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, line_number, format);
	return (format);
}

/**
 * find_func - finds appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *val, int ln, int format)
{
	int k;
	int show;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
	return;

	for (show = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
		call_fun(func_list[k].f, opcode, val, ln, format);
		show = 0;
		}
	}
	if (show == 1)
	err(3, ln, opcode);
}

/**
 * call_fun - Calls required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @value: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *value, int ln, int format)
{
	stack_t *node;
	int f;
	int k;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
		value = value + 1;
		f = -1;
		}
		if (value == NULL)
		err(5, ln);
		for (k = 0; value[k] != '\0'; k++)
		{
		if (isdigit(value[k]) == 0)
		err(5, ln);
		}
	node = create_node(atoi(value) * f);
	if (format == 0)
	func(&node, ln);
	if (format == 1)
	add_to_queue(&node, ln);
	}
	else
	func(&first, ln);
}
