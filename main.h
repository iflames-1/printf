#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define LEFT_JUSTIFY_FLAG 1
#define PLUS_FLAG 2
#define ZERO_PADDING_FLAG 4
#define ALTERNATE_FORM_FLAG 8
#define SPACE_FLAG 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct CustomFormat - Struct op
 *
 * @CustomFormat: The format.
 * @handler: The function associated.
 */
struct CustomFormat
{
	char CustomFormat;
	int (*handler)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct CustomFormat fmt_t - Struct op
 *
 * @CustomFormat: The format.
 * @fm_t: The function associated.
 */
typedef struct CustomFormat fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *CustomFormat, int *i,
va_list args, char buffer[], int flag, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* width handler */
int write_num(int ind, char bff[], int flag, int width, int precision,
	int length, char padd, char extraChar);
int write_pointer(char buffer[], int ind, int length,
	int width, int flag, char padd, char extraChar, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
	int flag, int width, int precision, int size);
int handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flag, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_string(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
	char buffer[], int flag, char flag_ch, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flag, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flag, int width, int precision, int size);

/****************** UTILS ******************/
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);


#endif /* MAIN_H */
