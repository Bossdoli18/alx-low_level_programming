#include "main.h"

/**
 * get_endianness -this functions looks for endianness
 * Return:here, it returns 0 when large endian and 1 when small endian
 */

int get_endianness(void)
{
	int y;

	y = 1;
	if (*(char *)&y == 1)
		return (1);
	else
		return (0);
}
