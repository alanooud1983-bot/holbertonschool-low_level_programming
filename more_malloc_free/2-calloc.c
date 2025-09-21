#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and sets bytes to 0
 * @nmemb: number of elements
 * @size:  size of each element
 * Return: pointer to memory, or NULL if nmemb/size is 0 or malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total, i;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;

	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return (p);
}
