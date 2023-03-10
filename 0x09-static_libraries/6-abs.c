#include "main.h"

/**
 * _abs - gives the absolute value of an integer
 * @n: the int to test
 * Return: the absolute value of int
 */

int _abs(int n)
{
	if(n < 0)
	{
		n = n * -1;
		return(n);
	}
	else
		return(n);
}
