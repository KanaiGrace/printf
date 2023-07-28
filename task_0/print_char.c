#include "main.h"

/**
 * print_char - print char
 *
 * @args: argument.
 *
 * Return: count of chars.
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	project_putchar(c);

	return (1);
}
