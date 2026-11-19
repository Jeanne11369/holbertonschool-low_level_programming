#include <stdio.h>
#include "dog.h"

/**
 * main - Tests dog creation and memory release
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
dog_t *my_dog;

my_dog = new_dog("Poppy", 3.5, "Bob");

if (my_dog == NULL)
{
printf("Failed to create dog\n");
return (1);
}

print_dog(my_dog);
free_dog(my_dog);

return (0);
}
