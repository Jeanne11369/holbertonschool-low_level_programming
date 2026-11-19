#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name_as_is - Prints a name
 * @name: Name to print
 */
void print_name_as_is(char *name)
{
printf("Hello, my name is %s\n", name);
}

/**
 * main - Tests print_name
 *
 * Return: Always 0
 */
int main(void)
{
print_name("Bob", print_name_as_is);

return (0);
}
