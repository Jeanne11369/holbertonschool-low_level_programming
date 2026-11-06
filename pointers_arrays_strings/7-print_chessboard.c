#include "main.h"

/**
 * print_chessboard - Prints an eight by eight chessboard
 * @a: Chessboard to print
 */
void print_chessboard(char (*a)[8])
{
	int row, column;

	for (row = 0; row < 8; row++)
	{
		for (column = 0; column < 8; column++)
			_putchar(a[row][column]);

		_putchar('\n');
	}
}
