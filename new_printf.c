#include "main.h"
void print_slip(char *str, int *char_string);
/**
 * _printf - The function that prints strings.
 * @format: The argument it takes for varidic functions.
 * Return: the length of character.
 */
int _printf(const char *format, ...)
{
int j, printed = 0;
int lenny, char_string = 0;
int flags, width, precision, size = 0;
char str[size_of];
va_list list_of_char;
if (format == NULL)
return (-1);
va_start(list_of_char, format);
for (j = 0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
str[char_string++] = format[j];
if (char_string == size_of)
print_slip(str, &char_string);
/* write(1, &format[j], 1); */
lenny++;
}
else
{
print_slip(str, &char_string);
flags = get_flags(format, &j);
width = get_width(format, &j, list_of_char);
precision = get_precision(format, &j, list_of_char);
size = get_size(format,  &j);
++j;
printed = handle_print(format, &j, list_of_char, str,
flags, width, precision, size);
if (printed == -1)
return (-1);
lenny += printed;
}
}
print_slip(str, &char_string);
va_end(list_of_char);
return (lenny);
}

/**
*print_slip -  prints the contents of the buffer if it exist
*@str: The string sha
*@char_string: The index
*/
void print_slip(char *str, int *char_string)
{
if (*char_string > 0)
write(1, &str[0], *char_string);
*char_string = 0;
}
