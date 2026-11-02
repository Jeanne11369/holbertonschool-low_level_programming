#include "main.h"

/**
 * print_square - Prints a square
 * @size: Length of each side
 */
void print_square(int size)
{
int row;
int column;

if (size <= 0)
{
_putchar('\n');
return;
}

for (row = 0; row < size; row++)
{
for (column = 0; column < size; column++)
{
_putchar('#');
}
_putchar('\n');
}
}
