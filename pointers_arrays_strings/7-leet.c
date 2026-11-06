#include "main.h"

/**
 * leet - Encodes a string using 1337 substitutions.
 * @s: String to modify.
 * Return: Pointer to s.
 */
char *leet(char *s)
{
	int i;
	int j;
	char letters[] = "aAeEoOtTlL";
	char digits[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = digits[j];
				break;
			}
		}
	}
	return (s);
}
