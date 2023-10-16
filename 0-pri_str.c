#include "main.h"
/**
 * _printf - The function that prints strings.
 * @format: The argument it takes for varidic functions.
 * Return: the length of character.
 */
int _printf(const char *format, ...)
{
int i, lenny, char_string = 0;

char c_str, *str;

va_list list_of_char;
if (format == NULL)
return (-1);
va_start(list_of_char, format);
while (*format)
{
if (*format != '%')
write(1, format, 1);
char_string++;
else
{
format++;
if (*format == '\0')
break;
else if (*format == '%')
write(1, format, 1);
char_string++;
else if (*format == 'c')
c_str = va_arg(list_of_char, int);
write(1, format, 1);
char_string++;
else if (*format == 's')
str = va_arg(list_of_char, char *);
for (; str[i] != '\0'; i++)
lenny++;
write(1, format, lenny);
char_string += lenny;
}
format++;
}
}
va_end(list_of_char);
return (char_string);
}
