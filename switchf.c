#include "holberton.h"

/**
 * switchf - determine which specifier to use
 * @format: format string from _printf
 * @buffer: buffer string from _printf
 * @i: location in @format
 * @n: location in @buffer
 * @args: arguments
 *
 * Return: new position in @format
 */
int switchf(const char *format, char *buffer, int i, int n, va_list args, int *size)
{
	switch (format[i])
	{
	case '%':
		buffer[n] = '%';
		buffer[n + 1] = '\0';
		i++;
		break;
	case 'c':
		buffer[n] = va_arg(args, int) + 0;
		if (buffer[n] == '\0')
		{
			_printstring(buffer);
			_putchar(0);
			*size += (n + 1);
			n = 0;
			i++;
			buffer[n] = '\0';
			break;
		}
		buffer[n + 1] = '\0';
		i++;
		break;
	case 's':
		i = string_app(buffer, va_arg(args, char *), i);
		break;
	case 'i':
		i = num_app(buffer, va_arg(args, int), i);
		break;
	case 'd':
		i = num_app(buffer, va_arg(args, int), i);
		break;
	default:
		buffer[n] = '%';
		buffer[n + 1] = '\0';
		break;
	}
	return (i);
}
