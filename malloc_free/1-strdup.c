#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string into a newly allocated memory
 * @str: source string
 *
 * Return: pointer to new string, or NULL on error/NULL input
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}
