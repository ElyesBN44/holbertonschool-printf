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
  <img src="https://carbon.now.sh/?bg=rgba%28208%2C2%2C27%2C1%29&t=seti&wt=none&l=text%2Fx-csrc&width=680&ds=true&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=56px&ph=56px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=%2523include%2520%253Climits.h%253E%250A%2523include%2520%253Cstdio.h%253E%250A%2523include%2520%2522main.h%2522%250A%250A%252F**%250A%2520*%2520main%2520-%2520Entry%2520point%250A%2520*%250A%2520*%2520Return%253A%2520Always%25200%250A%2520*%252F%250Aint%2520main%28void%29%250A%257B%250A%2520%2520%2520%2520int%2520len%253B%250A%2520%2520%2520%2520int%2520len2%253B%250A%2520%2520%2520%2520unsigned%2520int%2520ui%253B%250A%2520%2520%2520%2520void%2520*addr%253B%250A%250A%2520%2520%2520%2520len%2520%253D%2520_printf%28%2522Let%27s%2520try%2520to%2520printf%2520a%2520simple%2520sentence.%255Cn%2522%29%253B%250A%2520%2520%2520%2520len2%2520%253D%2520printf%28%2522Let%27s%2520try%2520to%2520printf%2520a%2520simple%2520sentence.%255Cn%2522%29%253B%250A%2520%2520%2520%2520ui%2520%253D%2520%28unsigned%2520int%29INT_MAX%2520%252B%25201024%253B%250A%2520%2520%2520%2520addr%2520%253D%2520%28void%2520*%290x7ffe637541f0%253B%250A%2520%2520%2520%2520_printf%28%2522Length%253A%255B%2525d%252C%2520%2525i%255D%255Cn%2522%252C%2520len%252C%2520len%29%253B%250A%2520%2520%2520%2520printf%28%2522Length%253A%255B%2525d%252C%2520%2525i%255D%255Cn%2522%252C%2520len2%252C%2520len2%29%253B%250A%2520%2520%2520%2520_printf%28%2522Negative%253A%255B%2525d%255D%255Cn%2522%252C%2520-762534%29%253B%250A%2520%2520%2520%2520printf%28%2522Negative%253A%255B%2525d%255D%255Cn%2522%252C%2520-762534%29%253B%250A%2520%2520%2520%2520_printf%28%2522Unsigned%253A%255B%2525u%255D%255Cn%2522%252C%2520ui%29%253B%250A%2520%2520%2520%2520printf%28%2522Unsigned%253A%255B%2525u%255D%255Cn%2522%252C%2520ui%29%253B%250A%2520%2520%2520%2520_printf%28%2522Unsigned%2520octal%253A%255B%2525o%255D%255Cn%2522%252C%2520ui%29%253B%250A%2520%2520%2520%2520printf%28%2522Unsigned%2520octal%253A%255B%2525o%255D%255Cn%2522%252C%2520ui%29%253B%250A%2520%2520%2520%2520_printf%28%2522Unsigned%2520hexadecimal%253A%255B%2525x%252C%2520%2525X%255D%255Cn%2522%252C%2520ui%252C%2520ui%29%253B%250A%2520%2520%2520%2520printf%28%2522Unsigned%2520hexadecimal%253A%255B%2525x%252C%2520%2525X%255D%255Cn%2522%252C%2520ui%252C%2520ui%29%253B%250A%2520%2520%2520%2520_printf%28%2522Character%253A%255B%2525c%255D%255Cn%2522%252C%2520%27H%27%29%253B%250A%2520%2520%2520%2520printf%28%2522Character%253A%255B%2525c%255D%255Cn%2522%252C%2520%27H%27%29%253B%250A%2520%2520%2520%2520_printf%28%2522String%253A%255B%2525s%255D%255Cn%2522%252C%2520%2522I%2520am%2520a%2520string%2520%21%2522%29%253B%250A%2520%2520%2520%2520printf%28%2522String%253A%255B%2525s%255D%255Cn%2522%252C%2520%2522I%2520am%2520a%2520string%2520%21%2522%29%253B%250A%2520%2520%2520%2520_printf%28%2522Address%253A%255B%2525p%255D%255Cn%2522%252C%2520addr%29%253B%250A%2520%2520%2520%2520printf%28%2522Address%253A%255B%2525p%255D%255Cn%2522%252C%2520addr%29%253B%250A%2520%2520%2520%2520len%2520%253D%2520_printf%28%2522Percent%253A%255B%2525%2525%255D%255Cn%2522%29%253B%250A%2520%2520%2520%2520len2%2520%253D%2520printf%28%2522Percent%253A%255B%2525%2525%255D%255Cn%2522%29%253B%250A%2520%2520%2520%2520_printf%28%2522Len%253A%255B%2525d%255D%255Cn%2522%252C%2520len%29%253B%250A%2520%2520%2520%2520printf%28%2522Len%253A%255B%2525d%255D%255Cn%2522%252C%2520len2%29%253B%250A%2520%2520%2520%2520_printf%28%2522Unknown%253A%255B%2525r%255D%255Cn%2522%29%253B%250A%2520%2520%2520%2520printf%28%2522Unknown%253A%255B%2525r%255D%255Cn%2522%29%253B%250A%2520%2520%2520%2520return%2520%280%29%253B%250A%257D%250A%2520%2520return%2520go%28f%252C%2520seed%252C%2520%255B%255D%29%250A%257D" alt="main.c code" style="max-width: 80%; height: auto;">
</div>
