#include "main.h"

/**
 * _strspn - function declaration
 * @s: source string
 * @accept: prefix substring
 * Return: number of bytes
 */

unsigned int _strspn(char *s, char *accept);

/**
 * _strspn - function definition
 * @s: the string to search
 * @accept: the prefic substring to be tested
 * Description: returns number of bytes in s
 * which only has bytes from accept
 * Return: number of bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int bytes = 0;
	int can;

	while (*s)
	{
		for (can = 0; accept[can]; can++)
		{
			if (*s == accept[can])
			{
				bytes++;
				break;
			}
			else if (accept[can + 1] == '\0')
			{
				return (bytes);
			}
		}
		s++;
	}
	return (bytes);
}
