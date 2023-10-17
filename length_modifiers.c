#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void custom_printf(const char *format, ...)
{   	va_list args;
	va_start(args, format);
	
	int i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			int length_modifier = 0;
			while (format[i] == 'l' || format[i] == 'h')
			{
				if (format[i] == 'l')
				{
					length_modifier++;
				}
				else if (format[i] == 'h')
				{
					length_modifier--;
				}
				i++;
			}
			switch (format[i])
			{
				case 'd':
				case 'i':
				case 'u':
				case 'o':
				case 'x':
				case 'X':
					{
						if (length_modifier == 1)
						{
							int num = va_arg(args, long int);
							printf("Got a long int: %ld\n", num);
						}
						else if (length_modifier == -1)
						{
							short int num = va_arg(args, short int);
							printf("Got a short int: %d\n", num);
						}
						else
						{
							int num = va_arg(args, int);
							printf("Got an int: %d\n", num);
						}
						i++;
						break;
					}
					default:
					putchar('%');
					break;
			}
		}
		else
		{
			putchar(format[i]);
		}
		i++;
	}
	va_end(args);
}
	int main(void)
	{
		custom_printf("%d, %ld, %hi\n", 42, 1234567890L, (short int)-32768);
		return (0);
	}
