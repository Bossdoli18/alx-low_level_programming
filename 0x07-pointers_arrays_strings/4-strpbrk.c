#include "main.h"

/**
 * *_strpbrk - function declaration
 * @s: string to search
 * @accept: bytes to search
 * Return: pointer or NULL
 */

char *_strpbrk(char *s, char *accept);

/**
 * *_strpbrk - function definition
 * @s: the string to be searched
 * @accept: bytes to search for
 * Description: searches for a string of a set of bytes
 * Return: pointer to matched byte or NULL if no match
 */

char *_strpbrk(char *s, char *accept)
{
	int str_can;
	int sub_str_can;

	for (str_can = 0; s[str_can] != '\0'; str_can++)
	{
		for (sub_str_can = 0; accept[sub_str_can] != '\0'; sub_str_can++)
		{
			if (s[str_can] == accept[sub_str_can])
			{
				return (s + str_can);
			}
		}
	}
	return (0);
}
