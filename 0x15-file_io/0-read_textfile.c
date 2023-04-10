#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and
 * prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of letters it should read and print.
 * Return: the actual number of letters it could read and print,
 * or 0 if failed.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t bytes_read, bytes_written;
char *buffer;

buffer = malloc((letters + 1) * sizeof(char));
if (!buffer)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buffer);
return (0);
}

bytes_read = read(fd, buffer, letters);
if (bytes_read == -1)
{
free(buffer);
close(fd);
return (0);
}

buffer[bytes_read] = '\0';

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
free(buffer);
close(fd);
return (0);
}

free(buffer);
close(fd);
return (bytes_written);
}


