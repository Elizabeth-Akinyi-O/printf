#include "main.h"

/**
 * format_string - Formats a string
 * @s: char*. The string
 *
 * Return: int. The number of characters formatted
 */
int format_string(char *s)
{
	unsigned int i, num_chars;

	i = 0;
	num_chars = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		num_chars++;
		i++;
	}

	return (num_chars);
}
