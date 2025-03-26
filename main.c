#include "main.h"

int int_to_string(int num, char *buffer)/* num = the integer to be converted , buffer = a pointer to a character array where the representation of num*/
{
	int i = 0, len = 0;/*i used as index to fill buffer*/
		/* len will store the length of the final string*/
	int j;/*used to invert the chain at the end*/
	int negative_n = 0;/*negative num indicator*/
    if (num == 0)/*Si num vaut 0, on met '0' dans buffer, on termine avec '\0', puis on retourne 1 car la chaîne contient un seul caractère*/
    {
        buffer[i++] = '0';
	buffer[i] = '\0';
	return 1;
    }
    else /*If num is negative :
Set the negative_n flag to 1.
Convert num to positive (num = -num) to facilitate digit extraction*/
	{
	if (num < 0)
	{
	negative_n = 1;
	num = -num;
	}
	while (num > 0)/*This while extracts the digits from the number:
	(num % 10) + '0' retrieves the last digit and converts it to an ASCII character.
	num /= 10 removes the last digit from num*/
	{
	buffer[i++] = (num % 10) + '0';
	num /= 10;
	}
	if (negative_n)/*If the original number was negative, add '-' to buffer*/
	buffer[i++] = '-';
    }
    buffer[i] = '\0';
    len = i;
    for (j = 0; j < i / 2; j++)/*The loop swaps characters to return the string to its original position*/
    {
        char temp = buffer[j];/*saves the current character*/
        buffer[j] = buffer[i - j -1];/*replace the beginning with the end*/
        buffer[i - j - 1] = temp;/* sets old character to end*/
    }
    return (len);/*The total length is returned*/
}

int my_strlen(const char *str)/*str is a pointer to a character string (char *)*/
				/*const signifie que la chaîne ne doit pas être modifiée dans cette fonction*/
{
	int length = 0;/*length is a variable that stores the length of the string*/

	while (str[length] != '\0')
	/*Go through the string character by character.
	str[length] retrieves the character at index length.
	As long as this character is not '\0' (the end-of-string character in C), length is incremented*/
	{
		length++;
	}
	return (length);
}
