#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers
 * @argc: Number of command-line arguments
 * @argv: Array containing the arguments
 *
 * Return: 0 (success), 1 (error)
 */
int main(int argc, char *argv[])
{
int a;
int b;

if (argc != 3)
{
printf("Error\n");
return (1);
}

a = atoi(argv[1]);
b = atoi(argv[2]);

printf("%d\n", a * b);

return (0);
}
