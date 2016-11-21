#include <unistd.h>

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

/**
 * _strlen - find length of string
 * @s: pointer to  string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int l;

	l = 0;
	while (*(s++) != '\0')
		l++;
	return (l);
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
