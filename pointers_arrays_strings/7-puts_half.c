#include "main.h"

/**
 * puts_half - Prints the second half of a string and a new line
 * @str: String to print
 */
void puts_half(char *str)
{
	int length;
	int start;

	length = 0;
	while (str[length] != '\0')
		length++;

	start = length / 2;
	if (length % 2 != 0)
		start++;

	while (start < length)
	{
		_putchar(str[start]);
		start++;
	}
	_putchar('\n');
}
