#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
* create_array - Create array of characters
* @size: Number of characters to allocate
* @c: Character used to initialize each element
*
* Return: Pointer to the array, or NULL on failure
*/
char *create_array(unsigned int size, char c)
{
unsigned int i;
char *array;

if (size == 0)
return (NULL);

array = malloc(size * sizeof(char));

if (array == NULL)
return (NULL);

i = 0;

while (i < size)
{
array[i] = c;
i++;
}

return (array);
}
