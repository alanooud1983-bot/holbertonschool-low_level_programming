#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a separator
 * @separator: string printed between strings (NULL => no separator)
 * @n: number of strings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *s;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator && i < n - 1)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
