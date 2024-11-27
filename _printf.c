#include "main.h"
/**
* _printf - produces output according to a format.
* @format: character string containing the format specifiers.
*
* Return: number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0;
int (*function)(va_list);
if (!format || (format[0] == '%' && format[1] == '\0'))
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%' && *(format + 1) != '%')
{
format++;
function = selector(*format);
if (!*format)
return (-1);
if (function)
i += function(args);
else
{
_putchar('%');
_putchar(*format);
i += 2;
}
}
else if (*format == '%' && *(format + 1) == '%')
{
format++;
_putchar('%');
i++;
}
else
{
_putchar(*format);
i++;
}
format++;
}
va_end(args);
return (i);
}
