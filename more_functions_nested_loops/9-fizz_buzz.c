#include <stdio.h>

/**
 * main - Prints numbers from 1 to 100 with FizzBuzz substitutions
 *
 * Return: Always 0
 */
int main(void)
{
int n;

for (n = 1; n <= 100; n++)
{
if (n > 1)
printf(" ");

if (n % 3 == 0 && n % 5 == 0)
printf("FizzBuzz");
else if (n % 3 == 0)
printf("Fizz");
else if (n % 5 == 0)
printf("Buzz");
else
printf("%d", n);
}
printf("\n");

return (0);
}
