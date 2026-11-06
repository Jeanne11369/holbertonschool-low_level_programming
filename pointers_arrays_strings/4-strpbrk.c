#include "main.h"

/**
 * _strpbrk - Searches a string for any accepted character
 * @s: String to search
 * @accept: String containing characters to find
 *
 * Return: Pointer to the first match, or a null pointer
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}

	return (0);
}
