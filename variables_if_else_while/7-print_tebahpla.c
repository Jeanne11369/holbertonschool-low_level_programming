#include <stdio.h>

/**
 * main - Print the lowercase alphabet in reverse
 *
 * Return: Always 0.
 */
int main(void)
{
char letter;

letter = 'z';
while (letter >= 'a')
{
putchar(letter);
letter--;
}
putchar('\n');

return (0);
}
