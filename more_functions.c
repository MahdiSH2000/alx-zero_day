#include "main.h"
/**
 * Afterpercentage - Checks if there are characters
 * @s: The string to check
 *
 * Return: 0 if only spaces follow '%', 1 otherwise
 */
int Afterpercentage(const char *s)
{
	if (s[0] == '%')
	{
		int i = 0;

		while (s[i + 1] != '\0')
		{
			if (s[i + 1] != ' ')
			{
				return (1);
				i++;
			}
		}
		return (0);
	}
	return (1);
}
/**
 * _strlen - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
