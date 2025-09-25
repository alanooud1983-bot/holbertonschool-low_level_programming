#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - simple calculator
 * @argc: number of arguments
 * @argv: array of arguments: argv[1]=a, argv[2]=op, argv[3]=b
 *
 * Return: 0 on success, 98 if argc wrong, 99 if op invalid
 * (div/mod by 0 prints "Error" and exits 100 inside op_div/op_mod).
 */
int main(int argc, char **argv)
{
	int a, b;
	int (*op)(int, int);

	if (argc != 4) { printf("Error\n"); return (98); }

	op = get_op_func(argv[2]);
	if (!op) { printf("Error\n"); return (99); }

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	printf("%d\n", op(a, b));
	return (0);
}
