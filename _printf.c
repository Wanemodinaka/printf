#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	
	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					putchar(*str);
					str++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
		}
		else
		{
			putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return printed_chars;
}
