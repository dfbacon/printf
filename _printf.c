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
	int i, n, temp, size;
	char buffer[1024];

	if (format == NULL)
		return (0);
	size = 0;
	va_start(args, format);
	i = n = temp = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			if (i > 1022)
			{
				_printstring(buffer);
				n = 0;
				buffer[n + 1] = '\0';
			}
			buffer[n] = format[i];
			i++;
			n++;
		}
		buffer[n] = '\0';
		if (format[i] == '%')
		{
			i++;
			temp = switchf(format, buffer, i, n, args, &size);
			i = temp;
		}
		n = _strlen(buffer);
	}
	va_end(args);
	_printstring(buffer);
	return (size + n);
}
