#include "main.h"

/**
 * *_memset - function declaration
 * @s: pointer to constant
 * @b: constant
 * @n: number of bytes
 * Return: pointer
 */

char *_memset(char *s, char b, unsigned int n);

/**
 * *_memset - function definition
 * @s: pointer to a constant
 * @b: constant to be used
 * @n: maximum number of bytes
 * Description: fills a memory address with constant byte
 * Return: pointer s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int can;

	for (can = 0; n > 0; can++)
	{
		s[can] = b;
		n--;
	}

	return (s);
}
