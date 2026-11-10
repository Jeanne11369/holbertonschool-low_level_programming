#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of characters
 * @size: Number of elements in the array
 * @c: Character used to initialize the array
 *
 * Return: Pointer to the array, or NULL on failure
 */

char *create_array(unsigned int size, char c)
{
    char *array;
    array = malloc(size * sizeof(char));
    
    if (array == NULL)
{
    return (NULL);
}

}