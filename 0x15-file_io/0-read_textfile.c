#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the maximum number of characters to read and print
 *
 * Return: If the function succeeds, the number of bytes read and printed.
 *         Otherwise, 0.
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
