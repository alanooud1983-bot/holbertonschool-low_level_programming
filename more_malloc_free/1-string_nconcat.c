#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenate s1 with first n bytes of s2
 * @s1: first string (treat NULL as "")
 * @s2: second string (treat NULL as "")
 * @n:  number of bytes to take from s2
 * Return: pointer to new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *p;

	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;

	if (n > len2)
		n = len2;

	p = malloc(len1 + n + 1);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		p[i] = s1[i];

	for (j = 0; j < n; j++)
		p[i + j] = s2[j];

	p[i + j] = '\0';
	return (p);
}
