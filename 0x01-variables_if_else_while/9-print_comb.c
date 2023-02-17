#include <stdio.h>

/**
 * main - program that prints all possible combinations of single-digit numbers
 * Return:  0 (Success)
 */
int main(void)
{
	int n;

	for (n = 13; n < 14; n++)
	{
		putchar(n);
		if (n != 13)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}

