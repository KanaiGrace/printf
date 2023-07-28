#include "main.h"
/**
 * _printf - print formatted text to stdout
 *
 * @format: format specifier
 * Return: number of bytes printed
 *
 */
int _printf(const char *format, ...)
{
	int i, count = 0, count_save;

	va_list args;

	va_start(args, format);

        if (!format || (format[0] == '%' && !format[1]))
                return (-1);
        if (format[0] == '%' && format[1] == ' ' && !format[2])
                return (-1);

	while (format[i])
	{
		count_save = 0;
		if (format[i] == '%')
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2]))
			{
				count = -1;
				break;
			}
			count_save += apply_function(format[i + 1], args);
			if (count_save == 0)
				count += project_putchar(format[i + 1]);
			if (count_save == -1)
				count = -1;
			i++;
		}
		else
		{
			(count == -1) ? (project_putchar(format[i])) : (count += project_putchar(format[i]));
		}
		i++;
		if (count != -1)
			count += count_save;
	}
	va_end(args);
	return (count);
}

