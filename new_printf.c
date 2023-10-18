#include "main.h"
/**
 * _printf - The function that prints strings.
 * @format: The argument it takes for varidic functions.
 * Return: the length of character.
 */
int _printf(const char *format, ...)
{
int num;
int char_string = 0;
char c_str, *str;
va_list list_of_char;
if (format == NULL)
return (-1);
va_start(list_of_char, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
char_string++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == '%')
{
write(1, format, 1);
char_string++;
}
else if (*format == 'c')
{
c_str = va_arg(list_of_char, int);
write(1, &c_str, 1);
char_string++;
}
else if (*format == 's')
{
str = va_arg(list_of_char, char*);
write(1, str, strlen(str));
char_string += strlen(str);
}
else if (*format == 'd' || *format == 'i')
num = va_arg(list_of_char, int);
char_string += print_number(num);
}
format++;
}
va_end(list_of_char);
return (char_string);
}
/**
 * print_number - Handle conversion specifiers
 * @n: Conversion specifier
 * Return: Number of characters printed for the specifier
 */
int print_number(int n)
{
char buffer[20];
int count = 0;
int i = 0;

if (n < 0)
{
write(1, "-", 1);
count++;
n = -n;
}

if (n == 0)
{
write(1, "0", 1);
count++;
}
else
{
while (n != 0)
{
buffer[i++] = '0' + n % 10;
n /= 10;
}

while (--i >= 0)
{
write(1, &buffer[i], 1);
count++;
}
}

return (count);
}

