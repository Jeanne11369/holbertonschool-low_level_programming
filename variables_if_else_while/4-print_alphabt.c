#include <stdio.h>

/**
 * main - Print lowercase alphabet except e and q
 *
 * Return: Always 0.
 */
int main(void)
{
char letter;

letter = 'a';
while (letter <= 'z')
{
if (letter != 'e' && letter != 'q')
putchar (letter);
letter++;
}
putchar('\n');

return (0);
}
