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
	unsigned int num_chars;
	int character, num;
	char *string;

	num_chars = 0;
	while (format != NULL)
	{
		va_start(args_ptr, format);
		while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				if (*format == 'c')
				{
					character = va_arg(args_ptr, int);
					num_chars += format_char(character);
				}
				else if (*format == '%')
				{
					num_chars += format_percent();
				}
				else if (*format == 's')
				{
					string = va_arg(args_ptr, char *);
					num_chars += format_string(string);
				}
				else if (*format == 'd' || *format == 'i')
				{
					num = va_arg(args_ptr, int);
					num_chars += format_num(num);
				}
				else
				{
					format--;
					_putchar(*format);
					format++;
					_putchar(*format);
					num_chars++;
				}
			}
			else
			{
				_putchar(*format);
				num_chars++;
			}
			format++;
		}
		va_end(args_ptr);
		break;
	}
	return (num_chars);
}
