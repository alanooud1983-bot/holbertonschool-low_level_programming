#include "function_pointers.h"

/**
 * int_index - returns index of first element for which cmp != 0
 * @array: array of integers
 * @size: number of elements in @array
 * @cmp:  pointer to comparing function (returns non-zero on match)
 * Return: index on success, or -1 if no match / invalid input
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
