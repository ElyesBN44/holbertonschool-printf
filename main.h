#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
* struct select - connects specifiers with the corresponding print functions.
* @c: format specifier.
* @f: pointer to the associated print function.
*/
typedef struct select
{
char c;
int (*f)(va_list);
} selecter_t;
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(__attribute__ ((unused)) va_list);
int print_int(va_list);
int print_decimal(va_list);
int (*selector(char specifier))(va_list args);
#endif
