#include "main.h"
#include <string.h>

/**
 * binary_to_uint - converts a binary string to an unsigned integer.
 * @binary: A pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is one or more chars
 *         in the string that is not 0 or 1, or if @binary is NULL.
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int result, pwr;
	int i;

	if (binary == NULL)
		return (0);

	for (i = 0; binary[i]; i++)
	{
		if (binary[i] != '0' && binary[i] != '1')
			return (0);
	}

	for (pwr = 1, result = 0, i--; i >= 0; i--, pwr *= 2)
	{
		if (binary[i] == '1')
			result += pwr;
	}

	return (result);
}

