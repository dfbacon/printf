#include <stdarg.h>
#include "holberton.h"

/**
 * _abs - computes absolute value of an integer
 * @i: interger to computer
 *
 * Return: absolute value;
 */
int _abs(int i)
{
	if (i < 0)
	{
		i = i * -1;
		return (i);
	}
	else
		return (i);
}

/**
 * _printnum - print integer
 * @args: int location
 * @buffer: original string to %
 *
 * Retrun: void
 */
int _printnum(va_list args)
{
	int i, j, k, value;
	int num[10];

	value = va_arg(args, int);
	i = j = k = 0;
	/* if value is negative */
	if (value < 0)
	{
		value = value * -1;
		_putchar('-');
		i++;
	}
	/* loop through num */
	for (j = 0; j < 10; j++)
	{
		/* changing num[j] to last digit of value */
		num[j] = value % 10;
		value = value / 10;
		if (value != 0)
			k++;
	}
	while (k >= 0)
	{
		/* print all characters */
		_putchar(num[k] + '0');
		k--;
		i++;
	}
	return (i);
}
