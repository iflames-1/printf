#include "main.h"

void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - Custom printf function
 *
 * @format: Format string
 *
 * Return: Number of characters printed_chars (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int format_index, printed_chars = 0, printed = 0;
	int flag, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	/* Check if format is NULL */
	if (format == NULL)
		return (-1);

	/* Start the variable argument args */
	va_start(args, format);

	/* Loop through the format string */
	for (format_index = 0; format && format[format_index] != '\0'; format_index++)
	{
		/* If character is not '%', add it to the buffer */
		if (format[format_index] != '%')
		{
			buffer[buff_index++] = format[format_index];

			/* Check if buffer is full, print its contents and reset index */
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);

			/* Increment the count of printed_chars characters */
			printed++;
		}
		else /* Handle format specifiers */
		{
			/* Print the current buffer contents */
			print_buffer(buffer, &buff_index);

			/* Parse flag, width, precision, and size from format */
			flag = get_flags(format, &format_index);
			width = get_width(format, &format_index, args);
			precision = get_precision(format, &format_index, args);
			size = get_size(format, &format_index);

			/* Move to the specifier character after '%' */
			++format_index;

			/* Process the format specifier and print its value */
			printed_chars = handle_print(format, &format_index, args, buffer,
				flag, width, precision, size);

			/* Check for error in handle_print and return -1 if needed */
			if (printed_chars == -1)
				return (-1);

			/* Increment the count of printed_chars characters */
			printed += printed_chars;
		}
	}

	/* Print any remaining characters in the buffer */
	print_buffer(buffer, &buff_index);

	/* End the variable argument args */
	va_end(args);

	/* Return the total number of printed_chars characters */
	return (printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 *
 * @buffer: Array of characters
 * @buff_index: Index at which to add next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	/* If buffer is not empty, print its contents */
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	/* Reset the buffer index */
	*buff_index = 0;
}
