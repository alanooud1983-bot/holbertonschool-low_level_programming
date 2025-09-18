#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenate two strings into a new allocated string
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: pointer to new "s1s2" string, or NULL if malloc fails
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, len1 = 0, len2 = 0;
	char *out;

	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;

	out = malloc((len1 + len2 + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];

	for (j = 0; j < len2; j++)
		out [i + j] = s2[j];

	out[i + j] = '\0';
	return (out);
}
