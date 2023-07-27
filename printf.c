#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * out_put0 - print single character
 * @v:holds value
 */
void out_put0(char v)
{
write(1, &v, 1);
}
/**
 * str_put - prints string
 * @string:points to string
 */
void str_put(const char *string)
{
while (*string)
{
out_put0(*string);
string++;
}
}
/**
 * int_put - convert integer to string
 * @num:holds value
 */
void int_put(int num)
{
char sent[20];
long unsigned int zero = 0;
int neg;
long unsigned int h;
char p;
if (num == 0)
{
sent[zero++] = '0';
}
else
{
neg = 0;
if (num < 0)
{
neg = 1;
num = -num;
}
while (num > 0 && zero < sizeof(sent) - 1)
{
sent[zero++] = '0' + (num % 10);
num /= 10;
}
if (neg && zero < sizeof(sent) - 1)
{
sent[zero++] = '-';
}
}
for (h = 0; h < zero / 2; h++)
{
p = sent[h];
sent[h] = sent[zero - 1 - h];
sent[zero - 1 - h] = p;
}
sent[zero] = '\0';
str_put(sent);
}
/**
 * _printf1 - printf handling d and i
 * @z:pointer
 * Return:0
 */
int _printf(const char *z, ...)
{
va_list numz;
va_start(numz, z);
while (*z)
{
if (*z != '%')
{
out_put0(*z);
}
else
{
z++;
if (*z == 'd' || *z == 'i')
{
int_put(va_arg(numz, int));
}
else
{
out_put0('%');
out_put0(*z);
}
}
z++;
}
va_end(numz);
return (0);
}

