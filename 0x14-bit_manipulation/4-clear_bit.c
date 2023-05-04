#include "main.h"
#include <stdio.h>

/**
 * clear_bit -this function clears the  index of a bit to 0
 * @n: this points to a number to be changed
 * @index: position of index to change
 * Return:this function returns 1 when success and -1 when it fails.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;
	unsigned int container;

	if (index > 64)
		return (-1);
	container = index;
	for (x = 1; container > 0; x *= 2, container--)
		;

	if ((*n >> index) & 1)
		*n -= x;

	return (1);
}
