#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

typedef struct print_func
{
	char type;
	int (*print_func)(va_list);
} print_func_t;

int int_to_string(int num, char *buffer);
int my_strlen(const char *str);
int _printf(const char *format, ...);
int spec_func(char format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);

#endif
