#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @CustomFormat: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flag
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *CustomFormat, int *ind, va_list args,
	char buffer[], int flag, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_char = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].CustomFormat != '\0'; i++)
		if (CustomFormat[*ind] == fmt_types[i].CustomFormat)
			return (fmt_types[i].handler(args, buffer, flag, width, precision, size));

	if (fmt_types[i].CustomFormat == '\0')
	{
		if (CustomFormat[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (CustomFormat[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (CustomFormat[*ind] != ' ' && CustomFormat[*ind] != '%')
				--(*ind);
			if (CustomFormat[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &CustomFormat[*ind], 1);
		return (unknow_len);
	}
	return (printed_char);
}
