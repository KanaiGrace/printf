#include "main.h"

/**
 * apply_function - function specifiers.
 *
 * @conv_spec: Conversion specifiers.
 * @args: arguments.
 *
 * Return: char count.
 */

int apply_function(char conv_spec, va_list args)
{
	int i = 0;
	int count_save = 0;

	specifiers_t spec[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_mod},
		{0, NULL}
	};

	while (spec[i].specifiers)
	{
		if (conv_spec == spec[i].specifiers)
			count_save += spec[i].f(args);
		i++;
	}

	if (count_save == 0)
	{
		count_save += project_putchar('%');
		count_save += project_putchar(conv_spec);
	}

	return (count_save);
}
