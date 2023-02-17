#include <stdio.h>

/**
 * main - program that  prints all possible different combinations of three digits
 * Return:  0 (Success)
 */
int main(void)
{
	int n, m, l;

	for (n = 37; n < 48; n++)
	{
		for (m = 38; m < 48; m++)
		{
			for (l = 39; l < 48; l++)
			{
				if (l > m && m > n)
				{
					putchar(n);
					putchar(m);
					putchar(l);
					if (n != 43 || m != 44)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

