#include "main.h"
/**
* print_char - Prints a single character.
* @args: The character to print (passed as a variadic argument).
*
* Return: The number of characters printed (always 1).
*/
int print_char(va_list args)
{
char c = va_arg(args, int);
_putchar(c);
return (1);
}
/**
* print_string - Prints a string.
* @args: The string to print (passed as a variadic argument).
*
* Return: The number of characters printed.
* If the string is NULL, prints "(null)" and returns 6.
*/
int print_string(va_list args)
{
char *s = va_arg(args, char *);
int i = 0;
if (!s)
s = "(null)";
while (s[i])
{
_putchar(s[i]);
i++;
}
return (i);
}
/**
 * print_percent - Prints %.
 * @args: Va_list.
 * Return: Count of percentage. 
*/
int print_percent(va_list args)
{
(void)args;
_putchar('%');
return(1);
}
/**
 * print_int - Prints an integer.
 * @args: The integer to print.
 * Return: The number of integers printed.
*/
