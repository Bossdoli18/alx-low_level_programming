#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index.
 * @n: The number to get the bit from.
 * @index: The index, starting from 0 of the bit to get.
 *
 * Return: The value of the bit at @index, or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int container;

	if (index > 63) /* Bit index is out of range. */
		return (-1);

	container = n >> index; /* Shift to the index bit. */

	return (container & 1); /* Get the bit at the index. */
}

