#include "holberton.h"

/**
 * string_app - append two strings
 * @base: initial string
 * @str: string to add
 * @location: position in format (i.e format[location])
 *
 * Return: pointer to appended base
 */
int string_app(char *base, char *str, int location)
{
	if (str == NULL)
	{
		_strcat(base, "(null)");
		return (location + 1);
	}
	else
	{
		_strcat(base, str);
		return (location + 1);
	}
}

/**
 * num_app - append string with converted number
 * @base: initial string
 * @num: number to be converted and added
 * @location: location in format (i.e. format[location])
 *
 * Return: pointer to appended base
 */
int num_app(char *base, int num, int location)
{
	char temp[100];

	/* convert number to string */
	itoa(num, temp);
	string_app(base, temp, 0);
	return (location + 1);
}

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

	size = 0;
	va_start(args, format);
	i = n = temp = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			if (i > 1022)
			{
				buffer[n] = '\0';
				_printstring(buffer);
				size += n;
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
			while (format[i] && format[i] == ' ')
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
