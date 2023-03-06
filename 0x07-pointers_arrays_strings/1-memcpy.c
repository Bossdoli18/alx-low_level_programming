#include "main.h"

/**
 * *_memcpy - function declaration
 * @dest: destination address
 * @src: source address
 * @n: number of times
 * Return: sring
 */

char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * *_memcpy - function definition
 * @dest: the destination address
 * @src: the source address
 * @n: number of times to copy
 * Description: copies the src to dest n times
 * Return: copied string
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int can;

	for (can = 0; can < n; can++)
	{
		dest[can] = src[can];
	}
	return (dest);
}
