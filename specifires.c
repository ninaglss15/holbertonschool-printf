#include <stdarg.h>
#include <unistd.h>
#include "main.h"
int spec_func(char format, va_list args)
{
	int j = 0;

	print_func_t print_funcs[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_integer},
	{'i', print_integer},
	{'\0', NULL}
};

	while (print_funcs[j].type != '\0')
	{
	if (format == print_funcs[j].type)
	return (print_funcs[j].print_func(args)); /* Exécute la bonne fonction */
	j++;
	}

	/* Si le format n'existe pas, affiche simplement "%" suivi du caractère inconnu */
	write(1, "%", 1);
	write(1, &format, 1);
	return (2);
}

int print_char(va_list args)
{
	char res = va_arg(args, int);
	return(write(1, &res, 1));
}

int print_string(va_list args)
{
	char *ptr = va_arg(args, char *);

	if (ptr == NULL)/*If the string is NULL, “(null)” is displayed*/
	ptr = "(null)";

	return (write(1, ptr, my_strlen(ptr)));
}

int print_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

int print_integer(va_list args)
{
	char buffer[100];
	int num = va_arg(args, int);/*retrieves the number to be displayed*/
	int len = int_to_string(num, buffer);
	/*we are gonna convert itto string because numbers cant
		be printed directly using write they need to be turned into string first*/
	write(1, buffer, len);
	return (len);
}
