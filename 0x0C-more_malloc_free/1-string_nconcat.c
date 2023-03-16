#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of s2 to concatenate
 * Return: pointer to concatenated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *p;
unsigned int i, j, len1, len2;

if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
for (len1 = 0; s1[len1]; len1++)
;
for (len2 = 0; s2[len2]; len2++)
;
if (n >= len2)
n = len2;
p = malloc(sizeof(char) * (len1 + n + 1));
if (p == NULL)
return (NULL);
for (i = 0; i < len1; i++)
p[i] = s1[i];
for (j = 0; j < n; j++)
p[i + j] = s2[j];
p[i + j] = '\0';
return (p);
}
