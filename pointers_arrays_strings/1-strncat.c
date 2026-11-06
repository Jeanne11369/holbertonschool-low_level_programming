#include "main.h"

/**
 * _strncat - Appends at most n characters from src.
 * @dest: Destination with enough space for the result.
 * @src: Source string.
 * @n: Maximum number of source characters to append.
 * Return: Pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
