#include "main.h"
/**
 * _check_format - Checks if the character is a valid format
 * @car: The character to check
 *
 * Return: 0 if character is valid, 1 otherwise
 */
int _check_format(const char car)
{
	int i = 0;
	char ch[] = {'c', 's', '%', 'i', 'd', 'b', 'u', 'o', 'x', 'X', 'S', 'p', 'r'};

	while (ch[i])
	{
		if (ch[i] == car)
			return (0);
		i++;
	}
	return (1);
}
/**
 * _printf - function that produces output according to a format
 * @format: parametre
 * Return:the number of characters printed
 */
int _printf(const char *format, ...)
{
	int len_count = 0;
	va_list myarg;

	if (format == NULL || ((*format == '%') && (*(format + 1) == '\0')))
		return (-1);

	if (Afterpercentage(format) == 0)
		return (0);

	va_start(myarg, format);
	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
	{
		format++;		/*To check next character*/
		if (_check_format(*(format + 1) == 0))
		{
			len_count += check_specifier(*(format + 1), myarg);
			format++;
		}
		else
		{
			write(1, format, 1);
			len_count += 1;
		}
		format++;	/*Next*/
	}
	va_end(myarg);
	return (len_count);
}
/**
 * check_specifier - Determines the appropriate function for a specifier
 * @t: Specifier character
 * @myarg: argument passes to the fucntion
 * Return: Pointer to the corresponding function or NULL
*/
int check_specifier(const char t, va_list myarg)
{
	int structsize;

	specifier_t checker_fct[] = {
		{'c', print_single_char_c},
		{'s', print_string_char_s}
	};
	structsize = sizeof(checker_fct) / sizeof(checker_fct[0]) - 1;
	while (structsize >= 0)
	{
		if (t == checker_fct[structsize].str)
		{
			break;
		structsize--;
		}
	}
	return (checker_fct[structsize].fct_op(myarg));
}
