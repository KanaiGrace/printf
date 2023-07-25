#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * out_put0 - prints out to standard output
 * @v:holds value
 */
void out_put0(char v)
{
write(1, &v, 1);
}
/**
 * int_put - force char to int
 * @num:hold char
 */
void int_put(int num)
{
char v = num + '0';
out_put0(v);
}
/**
 * _printf - handles convert specifiers d and i
 * @z:pointer
 * Return:0
 */
int _printf(const char *z, ...)
{
va_list specify;
int a;
int b;
va_start(specify, z);
for (; *z != '\0'; z++)
{
switch (*z)
{
case 'd':
a = va_arg(specify, int);
int_put(a);
break;
case 'i':
b = va_arg(specify, int);
int_put(b);
break;
}
}
return (0);
va_end(specify);
}
