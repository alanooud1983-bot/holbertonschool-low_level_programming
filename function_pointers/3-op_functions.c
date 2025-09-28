#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_add - adds two integers
 * @a: first integer
 * @b: second integer
 * Return: a + b
 */
int op_add(int a, int b)
{ return (a + b); }

/**
 * op_sub - subtracts two integers
 * @a: first integer
 * @b: second integer
 * Return: a - b
 */
int op_sub(int a, int b)
{ return (a - b); }

/**
 * op_mul - multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: a * b
 */
int op_mul(int a, int b)
{ return (a * b); }

/**
 * op_div - divides a by b
 * @a: numerator
 * @b: denominator
 * Return: a / b
 * Description: If @b is 0, prints "Error" and exits with status 100.
 */
int op_div(int a, int b)
{
	if (b == 0)

	{ printf("Error\n"); exit(100); }

	return (a / b);
}

/**
 * op_mod - computes the remainder of a divided by b
 * @a: first integer
 * @b: second integer
 * Return: a % b
 * Description: If @b is 0, prints "Error" and exits with status 100.
 */
int op_mod(int a, int b)
{
	if (b == 0)

	{ printf("Error\n"); exit(100); }

	return (a % b);
}
