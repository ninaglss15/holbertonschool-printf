#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
* main - Test file for verifying all required and edge cases for _printf
*
* Return: Always 0
*/

int main(void)
{
	int len, std_len;

	/* --- Test 1 : Chaîne vide --- */
	len = _printf("");
	std_len = printf("");
	printf("Test 1 : \"\" => %d | %d\n", len, std_len);

	/* --- Test 2 : Caractère (%c) --- */
	len = _printf("Lettre : %c\n", 'A');
	std_len = printf("Lettre : %c\n", 'A');
	printf("Test 2 : %%c => %d | %d\n", len, std_len);

	/* --- Test 3 : Chaîne (%s) --- */
	len = _printf("Texte : %s\n", "Bonjour");
	std_len = printf("Texte : %s\n", "Bonjour");
	printf("Test 3 : %%s => %d | %d\n", len, std_len);

	/* --- Test 4 : Chaîne NULL (%s) --- */
	len = _printf("Texte : %s\n", NULL);
	std_len = printf("Texte : %s\n", NULL);
	printf("Test 4 : %%s avec NULL => %d | %d\n", len, std_len);

	/* --- Test 5 : Pourcentage (%%) --- */
	len = _printf("100%% garanti\n");
	std_len = printf("100%% garanti\n");
	printf("Test 5 : %%%% => %d | %d\n", len, std_len);

	/* --- Test 6 : Caractère inconnu (%z) --- */
	len = _printf("Inconnu : %z\n");
	std_len = printf("Inconnu : %z\n");
	printf("Test 6 : %% inconnu => %d | %d\n", len, std_len);

	/* --- Test 7 : % seul à la fin --- */
	len = _printf("Un seul %%");
	std_len = printf("Un seul %%");
	printf("Test 7 : %% en fin => %d | %d\n", len, std_len);

	/* --- Test 8 : Double %% + texte --- */
	len = _printf("Double pourcent : %%%%OK\n");
	std_len = printf("Double pourcent : %%%%OK\n");
	printf("Test 8 : %%%% + texte => %d | %d\n", len, std_len);

	/* --- Test 9 : Entiers positifs (%d, %i) --- */
	len = _printf("Valeur d : %d, i : %i\n", 42, 99);
	std_len = printf("Valeur d : %d, i : %i\n", 42, 99);
	printf("Test 9 : %%d / %%i positifs => %d | %d\n", len, std_len);

	/* --- Test 10 : Entiers négatifs --- */
	len = _printf("Valeurs négatives : %d et %i\n", -123, -456);
	std_len = printf("Valeurs négatives : %d et %i\n", -123, -456);
	printf("Test 10 : %%d / %%i négatifs => %d | %d\n", len, std_len);

	/* --- Test 11 : INT_MAX / INT_MIN --- */
	len = _printf("Max : %d, Min : %d\n", INT_MAX, INT_MIN);
	std_len = printf("Max : %d, Min : %d\n", INT_MAX, INT_MIN);
	printf("Test 11 : INT_MAX / MIN => %d | %d\n", len, std_len);

	return (0);
}
