#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
/*
 * struct print_func - Structure for mapping format specifiers to functions
 * @type: The format specifier (e.g., 'c', 's', '%', 'd', etc.)
 * @print_func: Pointer to the corresponding function that handles printing
 */
typedef struct print_func
{
	char type;
	int (*print_func)(va_list);
} print_func_t;
/**
 * int_to_string - Converts an integer to a string
 * @num: The integer to convert
 * @buffer: Buffer to store the converted string
 *
 * Return: Length of the converted string
 */
int int_to_string(int num, char *buffer);
/**
 * my_strlen - Computes the length of a string
 * @str: The string whose length is to be determined
 *
 * Return: Length of the string
 */
int my_strlen(const char *str);
/**
 * _printf - Custom implementation of the printf function
 * @format: Format string containing format specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);
/**
 * spec_func - Determines which function to use for a given format specifier
 * @format: The format specifier
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed
 */
int spec_func(char format, va_list args);
/**
 * print_char - Prints a single character
 * @args: Variadic argument list (expects an int, cast to char)
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args);
/**
 * print_string - Prints a string
 * @args: Variadic argument list (expects a pointer to a string)
 *
 * Return: Number of characters printed
 */
int print_string(va_list args);
/**
 * print_percent - Prints a percent symbol '%'
 * @args: Variadic argument list (not used)
 *
 * Return: Number of characters printed (always 1)
 */

int print_percent(va_list args);
/**
 * print_integer - Prints an integer (Duplicate function, might be unnecessary)
 * @args: Variadic argument list (expects an integer)
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args);
/**
 * print_int - Prints an integer
 * @args: Variadic argument list (expects an integer)
 *
 * Return: Number of characters printed
 */
int print_int(va_list args);

#endif
