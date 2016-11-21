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
	int i, n, t, size, formats, temp;
	switchf_t switchf[] = {
		{"i", _printnum},
		{"c", _printchar},
		{}
	};
	formats = sizeof(switchf) / sizeof(switchf_t);
	if (formats == NULL)
		return (0);
	va_start(args, format);
	/* loop through format */
	n = i = size = 0;
	while (format[i])
	{
		t = 1;
		/* add characters to buffer */
		while (n < formats)
		{
			if (format[i] == '%' && format [i + 1] == '%')
				_putchar('%');
			if (format [i] == '%' &&
			    format [i + 1] == *(switchf[n].s))
			{
				temp = switchf[n].f(args);
				size += temp;
				t = 0;
			}
			n++;
		}
		if (t != 0)
		{
			write(1, &format[i], 1);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
