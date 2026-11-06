#include "main.h"

/**
 * _atoi - Converts the first digit sequence in a string to an integer
 * @s: String to examine
 *
 * Return: Converted integer, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int sign;
	int number;
	int digit;

	sign = 1;
	number = 0;
	while (*s != '\0' && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			sign = -sign;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		digit = *s - '0';
		if (sign == -1)
			number = number * 10 - digit;
		else
			number = number * 10 + digit;
		s++;
	}

	return (number);
}
