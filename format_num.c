#include "main.h"

/**
 * digit_count - Counts the number of digits
 * @num: int. The number
 *
 * Return: int. The digit count
 */
int digit_count(int num)
{
	unsigned int count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	return (count);
}

/**
 * format_num - Formats a number
 * @num: char*. The number
 *
 * Return: int. The number of characters formatted
 */
int format_num(int num)
{
	unsigned int num_chars, is_negative, num_digits, i;
	int divisor, digit;

	num_chars = 0;
	if (num == 0)
	{
		_putchar('0');
		num_chars++;
	}

	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	num_digits = digit_count(num);

	while (num_digits > 0)
	{
		divisor = 1;
		for (i = 1; i < num_digits; i++)
		{
			divisor *= 10;
		}
		digit = num / divisor;
		_putchar('0' + digit);
		num_chars++;
		num %= divisor;
		num_digits--;
	}

	if (is_negative)
	{
		_putchar('-');
		num_chars++;
	}

	return (num_chars);
}
