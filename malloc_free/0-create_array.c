#include "main.h"
#include <stdlib.h>

/**
 * create_array - make a char array filled with c
 * @size: number of bytes
 * @c: fill character
 *
 * Return: pointer to array, or NULL on fail/size 0
 */
char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);

	a = malloc(size * sizeof(char));
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		a[i] = c;

	return (a);
}
