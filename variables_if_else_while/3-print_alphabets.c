#include <stdio.h>

/**
 * main - Prints lowercase alphabet then uppercase
 *
 * Return: Always 0.
 */
int main(void)
{
char letter;

letter = 'a';
while (letter <= 'z')
{
putchar(letter);
letter++;
}

letter = 'A';
while (letter <= 'Z')
{
putchar(letter);
letter++;
}
putchar('\n');

return (0);
}
