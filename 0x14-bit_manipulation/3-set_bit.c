#include "main.h"

/**
 * set_bit -this function sets the index of a given bit to 1
 * @n:this is a  pointer to a number
 * @index: this bit changes index from 0
 * Return:this will return 1 when success and -1 when it fails.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > 64)
		return (-1);

	for (i = 1; index > 0; index--, i *= 2)
		;
	*n += i;

	return (1);
}
