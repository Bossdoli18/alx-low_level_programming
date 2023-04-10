#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: 0 on success, otherwise the appropriate error code
 */
int main(int argc, char **argv)
{
    int fd_from, fd_to, r, w, c;
    char buf[BUFSIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    while ((r = read(fd_from, buf, BUFSIZE)) > 0)
    {
        w = write(fd_to, buf, r);
        if (w != r)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
    }

    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    c = close(fd_from);
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    c = close(fd_to);
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}

