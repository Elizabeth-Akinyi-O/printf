#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: char *. The format string
 *
 * Return: int. The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args_ptr;
	unsigned int num_chars, i;
	int character;
	char *string;

	num_chars = 0;
	while (format != NULL)
	{
		va_start(args_ptr, format);
		i = 0;
		while (format[i] != '\0')
		{
			if (format[i] == '%' && format[i + 1] == 'c')
			{
				character = va_arg(args_ptr, int);
				num_chars += format_char(character);
				i++;
			}
			else if (format[i] == '%' && format[i + 1] == '%')
			{
				num_chars += format_percent();
				i++;
			}
			else if (format[i] == '%' && format[i + 1] == 's')
			{
				string = va_arg(args_ptr, char *);
				num_chars += format_string(string);
				i++;
			}
			else
			{
				_putchar(format[i]);
				num_chars++;
			}
			i++;
		}
		va_end(args_ptr);
		break;
	}
	return (num_chars);
}
