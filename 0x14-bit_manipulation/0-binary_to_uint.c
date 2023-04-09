#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
* binary_to_uint - converts a binary number to unsigned int
* @b: string containing the binary number
* Return: the converted number if there are characters
* o if string b is NULL
*/
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
	{
	return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
	if (b[i] == '0')
	{
	result = result * 2;
	}
	else if (b[i] == '1')
	{
	result = result * 2 + 1;
	}
	else
	{
	return (0);
	}

	}
	return (result);
}

