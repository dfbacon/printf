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
