#include "function_pointers.h"

/**
 * array_iterator - apply a function to each element of an int array
 * @array: pointer to the first element
 * @size: number of elements
 * @action: function pointer to apply on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (!array || !action)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
