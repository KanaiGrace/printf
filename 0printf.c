#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * out_put0 - prints single character to standard output
 * @v:holds value
 */
void out_put0(char v)
{
write(1, &v, 1);
}
/**
 * str_put - prints string
 * @string:pointer to string
 */
void str_put(const char *string)
