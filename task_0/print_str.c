#include "main.h"

/**
 * print_str - print string
 *
 * @c: string input
 * @args: argument
 *
 * Return: 1 On success. On error, -1 is returned,
 * and errno is appropriately set.
 */
int print_str(va_list args)
{
	int i;
	int count_save = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	if (str[0] == '\0')
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
		count_save += project_putchar(str[i]);

	return (count_save);
}

