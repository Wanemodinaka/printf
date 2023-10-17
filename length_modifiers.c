#include <stdio.h>
#include "main.h"

void custom_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i]) {
        if (format[i] == '%') {
            i++; // Move past '%'

            // Check for length modifiers
            int length_modifier = 0;
            while (format[i] == 'l' || format[i] == 'h') {
                if (format[i] == 'l') {
                    length_modifier++;
                } else if (format[i] == 'h') {
                    length_modifier--;
                }
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
                    // Handle the length modifier
                    if (length_modifier == 1) { // 'l' modifier
                        long int num = va_arg(args, long int);
                        // Format and output as needed
                        printf("Got a long int: %ld\n", num);
                    } else if (length_modifier == -1) { // 'h' modifier
                        short int num = va_arg(args, short int);
                        // Format and output as needed
                        printf("Got a short int: %d\n", num);
                    } else { // No length modifier
                        int num = va_arg(args, int);
                        // Format and output as needed
                        printf("Got an int: %d\n", num);
                    }

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
    custom_printf("%d, %ld, %hi\n", 42, 1234567890L, (short int)-32768);
    return 0;
}
