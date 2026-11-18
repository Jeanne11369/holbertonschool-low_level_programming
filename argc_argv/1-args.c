#include <stdio.h>

/**
 * main - Prints the number of arguments
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
printf("%d\n", argc - 1);

return (0);
}
