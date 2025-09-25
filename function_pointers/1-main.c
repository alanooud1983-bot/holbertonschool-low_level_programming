#include <stdio.h>
#include "function_pointers.h"

void print_elem(int elem)
{
	printf("%d\n", elem);
}

void print_elem_hex(int elem)
{
	printf("0x%x\n", elem);
}

int main(void)
{
	int array[] = {0, 98, 402, 1024, 4096};
	size_t size = sizeof(array) / sizeof(array[0]);

	array_iterator(array, size, print_elem);
	array_iterator(array, size, print_elem_hex);

	return (0);
}
