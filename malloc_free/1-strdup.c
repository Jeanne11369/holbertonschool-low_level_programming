#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string into newly allocated memory
 * @str: String to duplicate
 *
 * Return: Pointer to duplicate, or NULL on failure
 */
char *_strdup(char *str)
{
char *copy;
unsigned int i;
unsigned int len;

if (str == NULL)
return (NULL);

len = 0;
while (str[len] != '\0')
len++;

copy = malloc((len + 1) * sizeof(char));
if (copy == NULL)
return (NULL);

i = 0;
while (i <= len)
{
copy[i] = str[i];
i++;
}

return (copy);
}
