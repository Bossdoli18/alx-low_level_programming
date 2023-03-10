#include <unistd.h>

/**
 * _putchar - prints output to the standard output which is the monitor.
 * @c: The character to print
 *
 * Return: On success 1 is returned.
 * On error, -1 is returned, and error number is set appropriately.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
