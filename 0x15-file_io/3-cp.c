#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message and exits with the given status code
 * @status: the status code to exit with
 * @format: the format string for the error message
 */
void error_exit(int status, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    dprintf(STDERR_FILENO, "Error: ");
    vdprintf(STDERR_FILENO, format, args);
    dprintf(STDERR_FILENO, "\n");
    va_end(args);
    exit(status);
}

/**
 * main - entry point for the program
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t n_read, n_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
        error_exit(97, "Usage: %s file_from file_to", argv[0]);

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Can't read from file %s", argv[1]);

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Can't write to file %s", argv[2]);

    while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        n_written = write(fd_to, buffer, n_read);
        if (n_written != n_read)
            error_exit(99, "Can't write to file %s", argv[2]);
    }
    if (n_read == -1)
        error_exit(98, "Can't read from file %s", argv[1]);

    if (close(fd_from) == -1)
        error_exit(100, "Can't close fd %d", fd_from);

    if (close(fd_to) == -1)
        error_exit(100, "Can't close fd %d", fd_to);

    return 0;
}

