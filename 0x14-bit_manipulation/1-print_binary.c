#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints binary representation of a number
 * @n: number to print in a binary
 */

void print_binary(unsigned long int n)
{
unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
int found_one = 0;
while (mask > 0)
{
if ((n & mask) == mask)
{
putchar('1');
found_one = 1;
}
else if (found_one || mask == 1)
{
putchar('0');
}
mask >>= 1;
}
}

