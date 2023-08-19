#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: input to be formatted
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char *str_arg;

	va_start(args, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
			_putchar((char)va_arg(args, int));
			printed_chars++;
			}
			else if (*format == 's')
			{
				str_arg = va_arg(args, char *);
				if (!str_arg)
				str_arg = "(null)";
				while (*str_arg)
				{
					_putchar(*str_arg++);
					printed_chars++;
				}
			}
			else if (*format == '%')
			{	_putchar('%');
				printed_chars++;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
