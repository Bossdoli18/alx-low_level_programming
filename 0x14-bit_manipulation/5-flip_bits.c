#include "main.h"
#include <stdio.h>

/**
 * flip_bits -the flip_bits function reverses one number to another number
 * @n: ponits at the source number.
 * @m: points at the destination of the number.
 * Return: this function returns the amount of bits to fliped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int varying;
	int x;

	varying = n ^ m;
	x = 0;

	while (varying)
	{
		x++;
		varying &= (varying - 1);
	}

	return (x);
}
