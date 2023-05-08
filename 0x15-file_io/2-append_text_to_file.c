#include "main.h"

/**
 * append_text_to_file - adds text @the end of a file.
 * @filename: points to the file.
 * @text_content: string to append to the end of the file.
 *
 * Return: -1 if function fails, filename is NULL
 *	-1 file does not exist, or user lacks write permissions.
 *	Otherwise - return 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int opn, wt, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	opn = open(filename, O_WRONLY | O_APPEND);
	wt = write(opn, text_content, ln);

	if (opn == -1 || wt == -1)
		return (-1);

	close(opn);

	return (1);
}
