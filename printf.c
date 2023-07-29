#include "main.h"

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
int int_put(int num)
{
char sent[20];
unsigned long int zero = 0;
int neg;
unsigned long int h;
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
return (strlen(sent));
}
/**
 * _printf - printf handling d and i
 * @z:pointer
 * Return:0
 */
int _printf(const char *z, ...)
{
int letters = 0;
int len;
va_list numz;
va_start(numz, z);
while (*z)
{
if (*z != '%')
{
out_put0(*z);
letters++;
}
else
{
z++;
if (*z == 'd' || *z == 'i')
{
len = int_put(va_arg(numz, int));
letters += len;
}
else
{
out_put0('%');
out_put0(*z);
letters += 2;
}
}
z++;
}
va_end(numz);
return (letters);
}

/**
 * _printf0 - printf handling c, s and %
 * @format:pointer
 * Return:0
 */
int _printf0(const char *format, ...) 
{
va_list args;
int count;
char c;
char *s;
va_start(args, format);

while (*format) 
{
if (*format == '%') 
{
format++;
switch (*format) 
{
case 'c':
c = (char)va_arg(args, int);
putchar(c);
count++;
break;
case 's':
s = va_arg(args, char *);
while (*s) 
{
putchar(*s);
s++;
count++;
}
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
} else 
{
putchar(*format);
count++;
}
format++;
}

va_end(args);
return count;
}

