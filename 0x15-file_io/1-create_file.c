#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * main - creates the function file
 * create_file - Creates a file
 * @text_content: writes to a file
 * @filename: name of the file created
 * Return: 1 on success and -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
if (filename == NULL)
return (-1);

int fd;
ssize_t bytes_written;
size_t text_len = 0;


fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[text_len] != '\0')
text_len++;

bytes_written = write(fd, text_content, text_len);
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
