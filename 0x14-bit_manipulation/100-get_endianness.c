#include <stdio.h>
#include "main.h"
/**
* get_endianness - checks if a machine is little or big endian
* Return: 0 for big, 1 for little
*/
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *) &i;
if (*c)
{
/*The least significant byte is stored first (little-endian)*/
return (1);
}
else
{
/*The most significant byte is stored first (big-endian)*/
return (0);
}
}

