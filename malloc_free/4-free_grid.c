#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a two-dimensional array
 * @grid: Grid to free
 * @height: Number of rows
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
int i;

if (grid == NULL)
return;

i = 0;
while (i < height)
{
free(grid[i]);
i++;
}

free(grid);
}
