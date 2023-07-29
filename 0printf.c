#include "main.h"

/**
 * out_put0 - prints single character to standard output
 * @v:holds value
 */
void out_put0(char v)
{
write(1, &v, 1);
}

