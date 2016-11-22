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
 * itoa - convert integer to string
 * @num: integer to convert
 * @s: array of chars
 *
 * Return: int
 */
int itoa(int num, char s[])
{
	int i;

	i = 0;
	if (num / 10 != 0)
		i = itoa(num / 10, s);
	else if (num < 0)
		s[i++] = '-';
	/* make sure i is positive */
	s[i++] = _abs(num % 10) + '0';
	s[i] = '\0';

	return (i);
}
