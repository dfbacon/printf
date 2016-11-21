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
	int i, n, temp;
	char *buffer;
	switchf switchf_t[] = {
		{"i", _printnum},
		{"c", _printchar},
		{}
	}
	/* initialize buffer */
	buffer = _calloc(1, 1024);
	buffer[0] = '\0';

	va_start(args, format);

	/* loop through format */
	n = i = temp = 0;
	while (format[i])
	{
		/* add characters to buffer */
		while (format[i] && format[i] != '%')
		{
			buffer[n] = format[i];
			i++;
			n++;
		}

		/* add \0 to end */
		buffer[n] = '\0';

		/* convert '%' */
		if (format[i] == '%')
		{
			i++;
			while (temp > 3)
			{
				if (*switchf_t[temp].s == buffer[n])
				{
					switchf_t[temp].f(args, buffer);
				}
				temp++;
			}
		}
	}
	va_end(args);

	/* print buffer */
	/* _printstring(buffer); */
	write(1, buffer, 1024);
	free(buffer);
	return (n);
}
