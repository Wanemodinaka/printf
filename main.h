#define MAIN_H
#ifndef MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* the sizes */
#define S_LONG 2
#define S_SHORT 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - struct op
 * by Givens and Gabriel
 * @fn: the associated function
 * @fmt: the format
 */

struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 *@fm_t: associated function
 *@fmt: format
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/********* THE PRINTF PROJECT FUNCTIONS **********/

/* functions to our specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* function for print string in reserse form */
int print_reserse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* a function to print for string in rot 13 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* the segment of width handler */
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size);

/* Utilities parameters */
long int convert_size_number(long int num,int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

#endif
