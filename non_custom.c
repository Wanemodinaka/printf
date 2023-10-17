#include <stdio.h>
#include "main.h"

void custom_printf(const char *format, ...) 
{
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i]) {
        if (format[i] == '%') {
            i++; // Move past '%'
            int field_width = 0;

            // Check for a field width specifier
            while (format[i] >= '0' && format[i] <= '9') {
                field_width = field_width * 10 + (format[i] - '0');
                i++;
            }

            // Handle conversion specifiers
            switch (format[i]) {
                case 'd':
                case 'i':
                case 'u':
                case 'o':
                case 'x':
                case 'X': {
                    int num = va_arg(args, int);

                    // Calculate content width, padding width, and padding character
                    int content_width = snprintf(NULL, 0, format + i, num);
                    int padding_width = field_width - content_width;
                    char padding_char = ' '; // Use space as padding by default

                    // Adjust for negative numbers
                    if (num < 0) {
                        content_width++;
                        padding_width--;
                    }

                    // Output padding (if needed)
                    for (int j = 0; j < padding_width; j++) {
                        putchar(padding_char);
                    }

                    // Output content
                    printf(format + i, num);
                    i++;
                    break;
                }
                // Add handling for other conversion specifiers as needed
                default:
                    putchar('%');
                    break;
            }
        } else {
            putchar(format[i]);
        }
        i++;
    }

    va_end(args);
}

int main() {
    custom_printf("%5d, %8i, %03x, %4u\n", -42, 12345, 42, 7);
    return 0;
}
