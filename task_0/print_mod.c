#include "main.h"
#include <unistd.h>

/**
 * print_mod - print %.
 *
 * @args: arguments.
 *
 * Return: count of chars.
 */

int print_mod(va_list args)
{
	(void)args;

	project_putchar('%');

	return (1);
}
