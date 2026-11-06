#include "main.h"

/**
 * cap_string - Capitalizes words after the specified separators.
 * @s: String to modify.
 * Return: Pointer to s.
 */
char *cap_string(char *s)
{
	int i = 0;
	int j;
	int start = 1;
	char separators[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		if (start && s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - ('a' - 'A');
		start = 0;
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j])
			{
				start = 1;
				break;
			}
		}
		i++;
	}
	return (s);
}
