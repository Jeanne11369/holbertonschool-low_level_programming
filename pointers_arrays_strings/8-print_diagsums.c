#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sums of both matrix diagonals
 * @a: Matrix stored as consecutive integers
 * @size: Number of rows and columns
 */
void print_diagsums(int *a, int size)
{
	int i;
	int first = 0;
	int second = 0;

	for (i = 0; i < size; i++)
	{
		first += a[i * size + i];
		second += a[i * size + size - 1 - i];
	}

	printf("%d, %d\n", first, second);
}
