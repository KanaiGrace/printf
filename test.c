#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    char c;
    char *s;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    while (*s) {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'b': /* Custom specifier for binary */
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
                        while (mask > 0) {
                            putchar((num & mask) ? '1' : '0');
                            count++;
                            mask >>= 1;
                        }
                    }
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

