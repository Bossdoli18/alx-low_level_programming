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
    ssize_t opn, rd, wt, total = 0;
    char *buffer;

    if (filename == NULL)
        return (0);

    buffer = malloc(sizeof(char) * (letters + 1));
    if (buffer == NULL)
        return (0);

    opn = open(filename, O_RDONLY);
    if (opn == -1)
    {
        free(buffer);
        return (0);
    }

    while ((rd = read(opn, buffer, letters)) > 0)
    {
        wt = write(STDOUT_FILENO, buffer, rd);
        if (wt == -1 || wt != rd)
        {
            free(buffer);
            close(opn);
            return (0);
        }
        total += wt;
    }

    free(buffer);
    close(opn);

    if (rd == -1)
        return (0);

    return (total);
}
