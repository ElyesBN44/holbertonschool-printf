#include "main.h"
/**
 * print_decimal - prints a decimal.
 * @Ent: arg.
 * Return: count
*/
int print_decimal(va_list Ent)
{
unsigned int name, dec, number, account;
int d;
account = 0;
d = va_arg(Ent, int);
if (d < 0)
{
name = (d * -1);
acccount += _putchar('-');
}
else
name = d;
dec = name;
number = 1;
while (dec > 9)
{
dec /= 10;
number *= 10;
}
while (number >= 1)
{
account += _putchar(((name / number) % 10) + '0');
number /= 10;
}
return (account);
}
