#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings in new memory
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
char *result;
unsigned int len1 = 0, len2 = 0;
unsigned int i, j;

if (s1 != NULL)
{
while (s1[len1] != '\0')
len1++;
}

if (s2 != NULL)
{
while (s2[len2] != '\0')
len2++;
}

result = malloc((len1 + len2 + 1) * sizeof(char));
if (result == NULL)
return (NULL);

i = 0;
while (i < len1)
{
result[i] = s1[i];
i++;
}

j = 0;
while (j < len2)
{
result[i + j] = s2[j];
j++;
}

result[i + j] = '\0';

return (result);
}
