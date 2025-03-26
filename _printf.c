#include <stdarg.h>
#include <unistd.h>
#include<stdio.h>
#include "main.h"
/**
* _printf - printf function
* @format:specifies the format .can contain text and format specifiers
* Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
	int count = 0;/*Counter for number of characters displayed.*/
	unsigned int i;/*Scrolls the format string*/
	va_list args;

	va_start(args, format);/*Initialize args to access arguments*/

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			write(1, "%", 1);
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == '%')
				count += print_percent(args);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_integer(args);
			 else  /* For unknown characters after '%' */
            		{
                	write(1, "%", 1);  /* Print '%' */
                	write(1, &format[i], 1);  /* Print the unknown character */
                	count += 2;  /* Count both the '%' and the unknown character */
            		}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
