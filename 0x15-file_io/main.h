#ifndef FILE_IO_H
#define FILE_IO_H


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Reads a text file and prints its contents to the POSIX standard output. */
ssize_t read_textfile(const char *file_path, size_t num_bytes);

/* Creates a file and writes text content to it. */
int create_file(const char *file_path, char *file_content);

/* Appends text content to an existing file. */
int append_text_to_file(const char *file_path, char *file_content);

#endif
