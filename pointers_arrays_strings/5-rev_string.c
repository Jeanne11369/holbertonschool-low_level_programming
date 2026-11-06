#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: String to reverse
 */
void rev_string(char *s)
{
	int left;
	int right;
	char temp;

	right = 0;
	while (s[right] != '\0')
		right++;

	right--;
	left = 0;
	while (left < right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}
