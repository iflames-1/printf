#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @args: args of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list args)
{
	int next_index = *i + 1;
	int precision = -1;

	if (format[next_index] != '.')
		return (precision);

	precision = 0;

	for (next_index += 1; format[next_index] != '\0'; next_index++)
	{
		if (is_digit(format[next_index]))
		{
			precision *= 10;
			precision += format[next_index] - '0';
		}
		else if (format[next_index] == '*')
		{
			next_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = next_index - 1;

	return (precision);
}
