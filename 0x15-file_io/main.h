#ifndef MAIN_H
#define MAIN_H

/*
 * File: holberton.h
 * By: Nkwocha Chinedu (Chinaydu)
 * Dsc: This is a header file containing all the filr prototypes
 * they are just needed for this  0x15-file_io project.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
