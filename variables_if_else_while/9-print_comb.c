#include <stdio.h>

/**
 * main - Print single digits separated by commas and spaces
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
if (number < 9)
{
putchar(',');
putchar(' ');
}
number++;
}
putchar('\n');

return (0);
}
