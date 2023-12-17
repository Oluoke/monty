#include "monty.h"

/**
 * err - Prints necessary error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => if the program is unable to malloc more memory.
 * (5) => if the parameter passed to the instruction "push" is not an int.
 * (6) => if the stack it empty for pint.
 * (7) => if the stack it empty for pop.
 * (8) => if stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ga;
	char *op;
	int l_num;

	va_start(ga, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
			va_arg(ga, char *));
			break;
		case 3:
			l_num = va_arg(ga, int);
			op = va_arg(ga, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ga, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles more errors.
 * @error_code: The error codes are the following:
 *	(6) => if the stack it empty for pint.
 *	(7) => if the stack it empty for pop.
 *	(8) => if stack is too short for operation.
 *	(9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list ga;
	char *op;
	int l_num;

	va_start(ga, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
			va_arg(ga, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
			va_arg(ga, int));
			break;
		case 8:
			l_num = va_arg(ga, unsigned int);
			op = va_arg(ga, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
		va_arg(ga, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 *	(10) ~> The number inside a node is outside ASCII bounds.
 *	(11) ~> The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ga;
	int l_num;

	va_start(ga, error_code);
	l_num = va_arg(ga, int);
	switch (error_code)
	{
	case 10:
	fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	break;
	case 11:
	fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	break;
	default:
	break;
	}
		free_nodes();
		exit(EXIT_FAILURE);
}