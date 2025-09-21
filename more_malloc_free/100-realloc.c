#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocate a memory block
 * @ptr: previous block (or NULL)
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * Return: pointer to new block, or NULL on failure / when new_size is 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newp;
	char *oldp;
	unsigned int i;
	unsigned int limit;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	newp = malloc(new_size);
	if (newp == NULL)
		return (NULL);

	oldp = (char *)ptr;
	limit = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < limit; i++)
		newp[i] = oldp[i];

	free(ptr);
	return (newp);
}
