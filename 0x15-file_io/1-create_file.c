#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function to read a text file to the POSIX stdout.
 * @filename: points to the file name.
 * @letters: number of characters the
 *           function read and print.
 *
 * Return: 0 if filename is NULL or if function fail.
 *         O/w - number of bytes the function reads and prints.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t opn, rd, wt;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	opn = open(filename, O_RDONLY);
	rd = read(opn, buffer, letters);
	wt = write(STDOUT_FILENO, buffer, rd);

	if (opn == -1 || rd == -1 || wt == -1 || wt != rd)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(opn);

	return (wt);
}
