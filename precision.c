#include "main.h"
#include <stdarg.h>
/**
 * get_precision - Calculates the precision for formatting
 * @format: The format string that specifies the precision.
 * @i: A pointer to the current position in the format string.
 * @list: A va_list of arguments.
 *
 * Return: The calculated precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;

if (format[curr_i] != '.')
return (precision);

precision = 0;

for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}

*i = curr_i - 1;

return (precision);
}
