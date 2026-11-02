#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle
 * @size: Size of the triangle
 */
void print_triangle(int size)
{
int row;
int space;
int hash;

if (size <= 0)
{
_putchar('\n');
return;
}

for (row = 0; row < size; row++)
{
for (space = 0; space < size - row - 1; space++)
_putchar(' ');
for (hash = 0; hash < row + 1; hash++)
_putchar('#');
_putchar('\n');
}
}
