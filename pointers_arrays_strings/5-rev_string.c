#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: The string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, j;
	char temp;

	for (j = 0; s[j] != '\0'; j++)
		;

	for (i = 0, j = j - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
