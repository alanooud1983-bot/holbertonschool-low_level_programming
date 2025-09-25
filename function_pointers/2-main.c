#include <stdio.h>
#include "function_pointers.h"

int is_98(int n)        { return (n == 98); }
int is_strictly_pos(int n) { return (n > 0); }
int is_even(int n)      { return (n % 2 == 0); }

int main(void)
{
	int array[] = {0, 98, 402, 1024, -1024, 4096};
	int idx;

	idx = int_index(array, 6, is_98);
	printf("is_98 -> %d\n", idx);

	idx = int_index(array, 6, is_strictly_pos);
	printf("is_pos -> %d\n", idx);

	idx = int_index(array, 6, is_even);
	printf("is_even -> %d\n", idx);

	return (0);
}
