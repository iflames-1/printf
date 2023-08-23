#include "main.h"

/**
 * get_flags - Calculates active flag
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, next_index;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {LEFT_JUSTIFY_FLAG, PLUS_FLAG,
	ZERO_PADDING_FLAG, ALTERNATE_FORM_FLAG, SPACE_FLAG, 0};

	for (next_index = *i + 1; format[next_index] != '\0'; next_index++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[next_index] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = next_index - 1;

	return (flag);
}
