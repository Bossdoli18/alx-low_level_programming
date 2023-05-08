#include "main.h"

/**
 * create_file - function to file.
 * @filename: points to the name of the file to be created.
 * @text_content: points to string to be written
 *
 * Return: -1 if function fail.
 *         1 if success.
 */
int create_file(const char *filename, char *text_content)
{
	int opn, wt, ln = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (ln = 0; text_content[ln];)
			ln++;
	}

	opn = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wt = write(opn, text_content, ln);

	if (opn == -1 || wt == -1)
		return (-1);

	close(opn);

	return (1);
}
