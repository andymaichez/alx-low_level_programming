#include <stdio.h>

/**
 * main - program that  prints all possible different combinations of two digits
 * Return:  0 (Success)
 */
int main(void)
{
	int n, m;

	for (n = 21; n <= 35; n++)
	{
		for (m = 22; m <= 36; m++)
		{
			if (m > n)
			{
				putchar(n);
				putchar(m);
				if (n != 35 || m != 36)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

