#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * struct format - Struct for format
 * @specifiers: Struct format
 * @f: The function associated
 */

typedef struct specifiers
{
	char specifiers;
	int (*f)(va_list);
} specifiers_t;

/*prototypes*/

int _printf(const char *format, ...);
int project_putchar(char c);
int apply_function(char s, va_list args);

/*Conversion specifiers*/
int print_char(va_list args);
int print_str(va_list args);
int print_mod(va_list args);

#endif
