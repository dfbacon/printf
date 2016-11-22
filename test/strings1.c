#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * _putchar - writes character to stdout
 * @c: character to print
 *
 * Return: write
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - concatenate two strings
 * @dest: base string
 * @src: string to be added
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	i = 0;
	while (dest[i] != '\0')
		i++;
	for (n = 0; src[n] != '\0'; n++)
	{
		dest[i] = src[n];
		i++;
	}
	dest[i] = src[n];
	return (dest);
}

/**
 * _printchar - print a char
 * @args: char to print
 * @b: pointer to buffer
 *
 * Return: 1
 */
char *_printchar(char *base, va_list args)
{
	char *temp;
	int i;

	temp = malloc(100);
	i = va_arg(args, int);
	itoa(i, temp);
	_strcat(base, temp);
	free(temp);
	return (base);
}

/**
 * _printstr - print a string
 * @b: pointer to buffer
 * @args: string to print
 *
 * Return: length of str
 */
char *_printstr(char *base, va_list args)
{
	char *str;

	str = malloc(100);
	*str = va_arg(args, int);
	_strcat(base, str);
	free(str);
	return (base);
}

/**
 * _printstring - print string using _putchar
 * @string: string to print
 *
 * Return: 1 or - 1
 */
int _printstring(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
	_putchar('\0');
	return (1);
}
