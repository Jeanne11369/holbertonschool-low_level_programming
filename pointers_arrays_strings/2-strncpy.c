#include "main.h"

/**
 * _strncpy - Copies at most n characters and pads with null bytes.
 * @dest: Destination with space for at least n bytes.
 * @src: Source string.
 * @n: Number of bytes to write.
 * Return: Pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
