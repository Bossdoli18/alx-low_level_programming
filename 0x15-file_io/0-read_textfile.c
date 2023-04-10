#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    if (filename == NULL) {
        return 0;
    }

    char buffer[letters + 1]; // add 1 to allocate space for null terminator
    ssize_t num_read = 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    num_read = read(fd, buffer, letters);
    if (num_read == -1) {
        close(fd);
        return 0;
    }

    // add null terminator to end of buffer
    buffer[num_read] = '\0';

    ssize_t num_written = write(STDOUT_FILENO, buffer, num_read);
    close(fd);

    if (num_written == -1 || num_written != num_read) {
        return 0;
    }

    return num_written;
}

