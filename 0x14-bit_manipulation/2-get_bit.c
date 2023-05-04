#include "main.h"
#include <stdio.h>
/**
 * get_bit -here, this function gets the bit at a given index
 * @n: this is the bit to obtain
 * @index: this counter starts from 0, for the given bi
 * Return: the bit at index, or -1 when error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int container;

	if (index > 64)
		return (-1);

	container = n >> index;

	return (container & 1);
}
