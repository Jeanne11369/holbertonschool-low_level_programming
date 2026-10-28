#include <stdio.h>

/**
 * main - Print decimal digits using putchar
 *
 * Return: Always 0.
 */
int main(void)
{
int number;

number = 0;
while (number <= 9)
{
putchar(number + '0');
number++;
}
putchar('\n');

return (0);
}
