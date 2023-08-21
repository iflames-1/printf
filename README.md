0x11. C - printf
Group project


Compile with - gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

Tasks:
- Write a function that produces output according to a format.
	Prototype: int _printf(const char *format, ...);
	write output to stdout, the standard output stream
- Handle the following custom conversion specifiers:
	c, s, %, d, i, b, u, o, x, X, S, p
- Use a local buffer of 1024 chars in order to call write as little as possible.
- Handle the following flag characters for non-custom conversion specifiers:
	+, space, #
- Handle the field width for non-custom conversion specifiers.
- Handle the precision for non-custom conversion specifiers.
- 
