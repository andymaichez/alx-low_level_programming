/*
* File: 6-is_prime_number.c
*/
#include "main.h"
#include <stdio.h>
int is_divisible(int num, int div);
int is_prime_number(int n);
/**
* is_divisible - Checks if a number is divisible.
* @num: The number to be checked.
* @div: The divisor.
* Return: If the number is divisible - 0.
*/
int is_divisible(int num, int div)
{
if (num % div == 0)
return (0);
if (div == num / 2)
return (1);
return (is_divisible(num, div + 1));
}
