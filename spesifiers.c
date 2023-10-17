#include "main.h"
/**
 * print_single_char_c - Prints a single character
 * @myarg: Argument list containing the character to print
 *
 * Return: Always returns 1
 */
int print_single_char_c(va_list myarg)
{
	char c;

	c = va_arg(myarg, int);
	write(1, &c, 1);

	return (1);
}
/**
 * print_string_char*_s - Prints a string
 * @myarg: Argument list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string_char*_s(va_list myarg)
{
	char *str;

	str = va_arg(myarg, char *);
	if (str == NULL)
		return (_puts("(null)"));
	return (write(1, str, strlen(str)));
}
