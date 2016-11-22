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
	char buffer[1024], temp;
	int i, n, t, size, formats;
	print_format switchf[] = {
		{"i", _printnum},
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printnum},
	};
	size = t = 0;
	temp = malloc(sizeof(char));
	if (temp == NULL)
		return (size);
	formats = sizeof(switchf) / sizeof(print_format);
	va_start(args, format);
	/* loop through format */
	for (i = 0; format[i] != '\0'; i++)
	{
		n = 0;
		while (format[i] != '%')
		{
			buffer[n] = format[i];
			write(1, &format[i], 1);
			if (format[i] == '%')
			{
				i++;
				t = switchf[n].f(args, buffer);
				size += t;
			}
			n++;
		}
		size++;
	}
	va_end(args);
	return (size);
}
