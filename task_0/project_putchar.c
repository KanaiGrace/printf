#include "main.h"

/**
 * project_putchar - writes the character c to stdout
 * @c: character input
 *
 * Return: 1 On success. On error, -1 is returned,
 * and errno is appropriately set.
 */
int project_putchar(char c)
{
	return (write(1, &c, 1));
}

