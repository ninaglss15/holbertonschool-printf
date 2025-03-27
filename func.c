#include "main.h"
/**
 * int_to_string - Convert an integer to a string
 * @num: The integer to convert
 * @buffer: A buffer to store the resulting string
 *
 * Return: A pointer to the buffer containing representation of the number
 */
int int_to_string(int num, char *buffer)
{
	int i = 0, len = 0;
	int j;
	int negative_n = 0;

	if (num == 0)
	{
	buffer[i++] = '0';
	buffer[i] = '\0';
	return (1);
	}
	else
	{
	if (num < 0)
	{
	negative_n = 1;
	num = -num;
	}
	while (num > 0)
	{
	buffer[i++] = (num % 10) + '0';
	num /= 10;
	}
	if (negative_n)
	buffer[i++] = '-';
	}
	buffer[i] = '\0';
	len = i;
	for (j = 0; j < i / 2; j++)
	{
	char temp = buffer[j];

	buffer[j] = buffer[i - j - 1];
	buffer[i - j - 1] = temp;
	}
	return (len);
}
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
