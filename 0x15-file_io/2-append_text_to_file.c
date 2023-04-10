#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

/**
* append_text_to_file - appends the given text to the
* end of the given file.
* @filename: name of the file to append to.
* @text_content: null-terminated string to append to the file.
* Return: 1 on success, -1 on failure.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len])
len++;
}

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
bytes_written = write(fd, text_content, len);
if (bytes_written == -1 || bytes_written != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

