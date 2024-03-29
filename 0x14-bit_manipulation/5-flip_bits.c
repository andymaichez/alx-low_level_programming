#include <stdio.h>
#include "main.h"
/**
* flip_bits - counts the number of bits to flip
* @n: first number
* @m: second number
* Return: number of bits to flip
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int diff = n ^ m;
unsigned int count = 0;
while (diff)
{
count += diff & 1;
diff >>= 1;
}
return (count);
}

