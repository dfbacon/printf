#include "holberton.h"

/**
 * switchf - determine which specifier to use
 * @f: format string from _printf
 * @b: buffer string from _printf
 * @i: location in @f
 * @n: location in @b
 * @args: arguments
 * @size: size of buffer
 *
 * Return: new position in @format
 */
int switchf(const char *f, char *b, int i, int n,
	    va_list args, int *size)
{
	switch (f[i])
	{
	case '%':
		b[n] = '%';
		b[n + 1] = '\0';
		i++;
		break;
	case 'c':
		b[n] = va_arg(args, int) + 0;
		if (b[n] == '\0')
		{
			_printstring(b);
			_putchar(0);
			*size += (n + 1);
			n = 0;
			i++;
			b[n] = '\0';
			break;
		}
		b[n + 1] = '\0';
		i++;
		break;
	case 's':
		i = string_app(b, va_arg(args, char *), i);
		break;
	case 'i':
		i = num_app(b, va_arg(args, int), i);
		break;
	case 'd':
		i = num_app(b, va_arg(args, int), i);
		break;
	default:
		b[n] = '%';
		b[n + 1] = '\0';
		break;
	}
	return (i);
}
