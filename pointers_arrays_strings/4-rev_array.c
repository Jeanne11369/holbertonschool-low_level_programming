#include "main.h"

/**
 * reverse_array - Reverses an integer array in place.
 * @a: Array to reverse.
 * @n: Number of elements.
 */
void reverse_array(int *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
