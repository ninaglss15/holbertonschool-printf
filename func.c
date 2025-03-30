#include "main.h"
/**
 * my_strlen - Finds the length of a character string
 * @str: Pointer to the character string
 *
 * Return: The length of the string (not counting the null terminator)
 */
int my_strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

