#include "main.h"

void print_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int j, char_str  = 0;
int flags, width, precision, size = 0;
int buffer_index, char_printed = 0;
va_list list_of_char;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(list_of_char, format);
for (j = 0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
buffer[buffer_index++] = format[j];
if (buffer_index == BUFF_SIZE)
print_buffer(buffer, &buffer_index);
/*write(1, &format[j], 1) */
char_printed++;
}
else
{
print_buffer(buffer, &buffer_index);
flags = get_flags(format, &j);
width = get_width(format, &j, list_of_char);
precision = get_precision(format, &j, list_of_char);
size = get_size(format, &j);
++j;

char_str = handle_print(format, &j, list_of_char, buffer,
flags, width, precision, size);
if (char_str == -1)
return (-1);
char_printed += char_str;
}
}
print_buffer(buffer, &buffer_index);
va_end(list_of_char);
return (char_printed);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

*buffer_index = 0;
}
