<div align="center">
    <h1 style="font-family: Arial, sans-serif; color: #2c3e50; font-size: 36px; margin: 20px 0;">
        Custom <code>_printf</code> Function
    </h1>
</div>
<div align="center">
 <img src="https://miro.medium.com/v2/resize:fit:720/format:webp/1*M05Idy6FOOgxJMcE4LfFYw@2x.jpeg" alt="Example of printf" style="display: block; padding-bottom: 20px; padding-top: 20px; width: 100%; max-width: 600px; margin-left: auto; margin-right: auto;">
</div>
<div style="text-align: left; margin: 0 auto; max-width: 800px; font-size: 18px; line-height: 1.6;">
    <p>
        This project involved creating a custom implementation of the <code>printf</code> function using the C programming language. 
        The <code>_printf</code> function takes a format string (<code>const char *format</code>) and a list of arguments. 
        It processes the format string, analyzing it for specific patterns or format specifiers (like <code>%c</code> for characters 
        or <code>%s</code> for strings). Once a match is identified, the corresponding handler function is called to generate the 
        appropriate output.
    </p>
</div>
<h2 style="text-align: center; color: #2c3e50;">Patterns</h2>
<div style="margin: 0 auto; max-width: 800px; text-align: center;">
    <table style="width: 100%; border-collapse: collapse; margin: 20px 0; font-size: 16px; border: 1px solid #ddd;">
        <thead>
            <tr style="background-color: #f2f2f2;">
                <th style="padding: 10px; border: 1px solid #ddd;">Specifier</th>
                <th style="padding: 10px; border: 1px solid #ddd;">Output</th>
                <th style="padding: 10px; border: 1px solid #ddd;">Examples</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td style="padding: 10px; border: 1px solid #ddd;"><code>%c</code></td>
                <td style="padding: 10px; border: 1px solid #ddd;">Character</td>
                <td style="padding: 10px; border: 1px solid #ddd;"><code>y</code></td>
            </tr>
            <tr>
                <td style="padding: 10px; border: 1px solid #ddd;"><code>%s</code></td>
                <td style="padding: 10px; border: 1px solid #ddd;">String of characters</td>
                <td style="padding: 10px; border: 1px solid #ddd;"><code>Elyess Yassine </code></td>
            </tr>
        </tbody>
    </table>
</div>
<h2 style="text-align: center; color: #2c3e50;">Files</h2>

<div style="margin: 0 auto; max-width: 800px; text-align: left;">
    <table style="width: 100%; border-collapse: collapse; font-size: 14px;">
        <thead>
            <tr style="background-color: #ecf0f1;">
                <th style="border: 1px solid #bdc3c7; padding: 8px; text-align: left;">File Name</th>
                <th style="border: 1px solid #bdc3c7; padding: 8px; text-align: left;">Description</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">_printf.c</td>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">This file contains the main implementation of the <code>_printf</code> function. It processes the format string, identifies conversion specifiers, and delegates to corresponding handler functions to print the appropriate output.</td>
            </tr>
            <tr>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">handlers.c</td>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">This file defines the handler functions for each conversion specifier. For example, the <code>print_char</code> and <code>print_string</code> functions handle <code>%c</code> and <code>%s</code> respectively.</td>
            </tr>
            <tr>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">_putchar.c</td>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">This file contains the implementation of the <code>_putchar</code> function, which is used to write a single character to the standard output.</td>
            </tr>
            <tr>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">selector.c</td>
                <td style="border: 1px solid #bdc3c7; padding: 8px;">This file contains logic to select the correct handler based on the conversion specifier. It matches the format specifiers in the format string with the appropriate function for processing and output.</td>
            </tr>
        </tbody>
    </table>
</div>
<h2>main.c</h2>
<p>To verify the functionality of the custom _printf function, a main.c file was used. This file tests various format specifiers and compares the output from _printf with that of the standard printf. It includes tests for different data types, such as integers, characters, and strings, ensuring that the custom function works as expected across a wide range of inputs. Below is the image of the code snippet used for testing the implementation.</p>

<div>
```c
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
</div>
