#include "main.h"

/**
 * *_strchr - function declaration
 * @s: the string
 * @c: the character
 * Return: a character
 */
char *_strchr(char *s, char c);

/**
 * *_strchr - function definition
 * @s: the string to be searched
 * @c: the character to find
 * Description: finds a character in a string
 * Return: a character value
 */

char *_strchr(char *s, char c)
{
	int can;

	for (can = 0; s[can] != '\0'; can++)
	{
		if (s[can] == c)
		{
			return (s + can);
		}
	}
	if (s[can] == c)
	{
		return (s + can);
	}
	return (0);
}
