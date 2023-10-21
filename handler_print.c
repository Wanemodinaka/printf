#include <unistd.h>  /* for write */
#include "main.h"

/**
 * print_string - Print a string
 * @buffer: Character buffer.
 * @list: Arguments list.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * @width: Width specifier.
 * @flags: Flag modifiers.
 *
 * Return: Number of characters printed.
 */
int print_string(char buffer[], va_list list, int precision, int size, int width, int flags);
{
	char *str = va_arg(list, char *);
	(void)precision;
	(void)size;
	(void)width;
	(void)flags;
	
	int length = 0;
	
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (width > 0)
		{
			buffer[length] = *str;
			length++;
			width--;
		}
		else
		{
			write(1, str, 1);  /* Print one character */
			length++;
		}
		str++;
	}
	return length;
}
