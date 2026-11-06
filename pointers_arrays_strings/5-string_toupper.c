#include "main.h"

/**
 * string_toupper - Converts lowercase ASCII letters to uppercase.
 * @s: String to modify.
 * Return: Pointer to s.
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('a' - 'A');
		i++;
	}
	return (s);
}
