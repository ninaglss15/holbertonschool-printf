#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "main.h"
/**
 * spec_func - Selects the appropriate function based on format specifier
 * @format: Character indicating the type of format
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed
 */
int spec_func(char format, va_list args)
{
	int j = 0;

	print_func_t print_funcs[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_int},
	{'i', print_int},
	{'\0', NULL}
};

	while (print_funcs[j].type != '\0')
	{
	if (format == print_funcs[j].type)
	return (print_funcs[j].print_func(args)); /* Exécute la bonne fonction */
	j++;
	}

	write(1, "%", 1);
	write(1, &format, 1);
	return (2);
}
/**
 * print_char - Prints a single character
 * @args: List of variadic arguments (expects an int but cast to char)
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
	char res = va_arg(args, int);

	return (write(1, &res, 1));
}
/**
 * print_string - Prints a string
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *ptr = va_arg(args, char *);

	if (ptr == NULL)/*If the string is NULL, “(null)” is displayed*/
	ptr = "(null)";

	return (write(1, ptr, my_strlen(ptr)));
}
/**
 * print_percent - Prints a percent symbol "%"
 * @args: List of variadic arguments (not used here)
 *
 * Return: Number of characters printed (always 1)
 */
int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
/**
 * print_int - Prints a signed integer
 * @args: List of variadic arguments (expects an int)
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	unsigned int abs_num;
	int len = 0;
	unsigned int divisor;
	char digit;

	if (num < 0)
	{
		write(1, "-", 1);
		len++;
		abs_num = (unsigned int)(-num);
	}
	else
	{
		abs_num = (unsigned int)num;
	}

	if (abs_num == 0)
	{
		write(1, "0", 1);
		return (len + 1);
	}

	divisor = 1;

	for (; abs_num / divisor > 9; divisor *= 10)
	;

	for (; divisor > 0; divisor /= 10)
	{
		digit = (char)((abs_num / divisor) + '0');
		write(1, &digit, 1);
		abs_num %= divisor;
		len++;
	}

	return (len);
}

