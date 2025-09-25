#include <stddef.h>
#include "function_pointers.h"

/**
 * print_name - calls a function pointer on a given name
 * @name: string to print/process
 * @f: function pointer taking (char *) and returning void
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
