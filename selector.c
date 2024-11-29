#include "main.h"
/**
* selector - selects the correct function to call
* @specifier: the format specifier.
*
* Return: pointer to the appropriate function.
* Returns NULL if no matching specifier is found.
*/
int (*selector(char specifier))(va_list args)
{
int i;
selecter_t tab[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_decimal},
{'i', print_int},
{'\0', NULL},
};
for (i = 0; tab[i].c != '\0'; i++)
{
if (tab[i].c == specifier)
return (tab[i].f);
}
return (NULL);
}
