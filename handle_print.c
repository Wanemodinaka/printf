#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_print - prints arguments based on their types
 * @fmt: the format string
 * @ind: pointer to the index in the format string
 * @list: arguments list
 * @buffer: buffer array to handle print
 * @flags: active flags calculations
 * @width: width specifier
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of characters printed.
 */

int handle_print(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size)
{
	int i;
	int printed_chars = 0;
       	fmt_t fmt_types[] =
	{
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			printed_chars += fmt_types[i].fn(list, buffer, precision, size, width, flags);
			return (printed_chars);
		}
	}
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
		{
			return (-1);
		}
		if (fmt[*ind - 1] == ' ')
		{
			printed_chars += write(1, " ", 1);
		}
		else if (width)
		{
			(*ind)--;
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				(*ind)--;
			}
			if (fmt[*ind] == ' ')
			{
				(*ind)--;
			}
			return (1);
		}
		printed_chars += write(1, &fmt[*ind], 1);
	}
	return (printed_chars);
}

