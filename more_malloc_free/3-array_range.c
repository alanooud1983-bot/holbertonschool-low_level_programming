#include <stdlib.h>
#include "main.h"

/**
 * array_range - create an int array from min to max (inclusive)
 * @min: first value
 * @max: last value
 * Return: pointer to new array, or NULL on error
 */
int *array_range(int min, int max)
{
	int *a;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	a = malloc(sizeof(int) * size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		a[i] = min + i;

	return (a);
}
