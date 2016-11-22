#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _printf - replicate the printf function
 * @format: character string
 *
 * Return: number of characters printed (not including '\0')
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *buffer;
	int i, n;
	print_format switchf[] = {
		{"i", _printnum},
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printnum},
	};

	va_start(args, format);
	/* loop through format */
	for (i = 0; format[i] != '\0'; i++)
	{
		n = 0;
		while (format[i] != '%')
		{
			buffer[n] = format[i];
			if (format[i] == '%')
			{
				i++;
				buffer = switchf[n].f(buffer, args);
			}
			n++;
		}
	}
	_printstring(buffer);
	va_end(args);
	return (i);
}
