#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: String to search
 * @c: Character to find
 *
 * Return: Pointer to the first match, or a null pointer
 */
char *_strchr(char *s, char c)
{
	while (1)
	{
		if (*s == c)
			return (s);

		if (*s == '\0')
			return (0);

		s++;
	}
}
