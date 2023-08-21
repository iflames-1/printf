#include "main.h"

void print_buffer(char buffer[], int *buff_index);
/**
 * _printf - Custom printf function
 *
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_char = 0;
	int flag, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	/* Check if format is NULL */
	if (format == NULL)
		return (-1);

	/* Start the variable argument args */
	va_start(args, format);

	/* Loop through the format string */
	for (j = 0; format && format[j] != '\0'; j++)
	{
		/* If character is not '%', add it to the buffer */
		if (format[j] != '%')
		{
			buffer[buff_index++] = format[j];

			/* Check if buffer is full, print its contents and reset index */
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);

			/* Increment the count of printed characters */
			printed_char++;
		}
		else /* Handle format specifiers */
		{
			/* Print the current buffer contents */
			print_buffer(buffer, &buff_index);

			/* Parse flag, width, precision, and size from format */
			flag = get_flags(format, &j);
			width = get_width(format, &j, args);
			precision = get_precision(format, &j, args);
			size = get_size(format, &j);

			/* Move to the specifier character after '%' */
			++j;

			/* Process the format specifier and print its value */
			printed = handle_print(format, &j, args, buffer,
				flag, width, precision, size);

			/* Check for error in handle_print and return -1 if needed */
			if (printed == -1)
				return (-1);

			/* Increment the count of printed characters */
			printed_char += printed;
		}
	}

	/* Print any remaining characters in the buffer */
	print_buffer(buffer, &buff_index);

	/* End the variable argument args */
	va_end(args);

	/* Return the total number of printed characters */
	return (printed_char);
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
