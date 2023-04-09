#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - checks the main file
 * read_textfile - reads a text file and prints it
 * @letters : number of letters it should read and print
 * @filename: file being read
 * Return: actual number of letters it could read and print
 * 0 when the file fails, NULL or  can'tbe opened
 */
int main(void)
ssize_t read_textfile(const char *filename, size_t letters);
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	return (0);

	char *buffer = (char *) malloc(letters * sizeof(char));

	if (buffer == NULL)
	{
		return (0);
	}
	ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);

	fclose(file);

	ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);

	if (bytes_written != bytes_read)
	return (0);
	return (bytes_written);
}
