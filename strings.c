#include <stdarg.h>
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
 * _printchar - print a char
 * @args: char to print
 * @b: pointer to buffer
 *
 * Return: 1
 */
int _printchar(va_list args, char *b)
{
	char *p;

	p = malloc(sizeof(*p));
	*p = (char)va_arg(args, int);
	if (p == NULL)
		return (0);
	_putchar(*p);
	free(p);
	return (1);
}

/**
 * _printstr - print a string
 * @args: string to print
 * @b: pointer to buffer
 *
 * Return: length of str
 */
int _printstr(va_list args, char *b)
{
	char *tmp;
	int i;

	i = 0;
	tmp = va_arg(args, char *);
	while (*tmp != 0)
	{
		_putchar(*tmp);
		tmp++;
		i++;
	}
	return (i);
}
